#include <iostream>
#include <string>
#include <list>
#include <iomanip>
using namespace std;

int credits = 3;

class Course {
    public:          // Access specifier
    string course_name;
    float grade_point;    // Attribute
    
    Course(string co, float gr) { 
    course_name = co;
    grade_point = gr;
    }

   // Course(string co, float gr) : course_name(co), grade_point(gr) {}
 
    float calculate_points() const {
        return credits * grade_point;
    }
};

int main() {
    list<Course> courses;
    int total_courses;
    string course_name;
    std::string course_grade;
    float gradePoint = 0.0;


    cout << "How many courses would you like to input to calculate GPA: " ;
    cin >> total_courses;

    for (int i = 0; i < total_courses; i++) {
        cout << "Enter Course Name: ";
        cin >> course_name;
        
        cout << "Enter Letter Grade: ";
        cin >> course_grade;
        
        if (course_grade == "A+" || course_grade == "A") {
            gradePoint = 4.0;
        } else if (course_grade == "A-") {
            gradePoint = 3.7;
        } else if (course_grade == "B+") {
            gradePoint = 3.3;
        } else if (course_grade == "B") {
            gradePoint = 3.0;
        } else if (course_grade == "B-") {
            gradePoint = 2.7;
        } else if (course_grade == "C+") {
            gradePoint = 2.3;
        } else if (course_grade == "C") {
            gradePoint = 2.0;
        } else if (course_grade == "C-") {
            gradePoint = 1.7;
        } else if (course_grade == "D+") {
            gradePoint = 1.3;
        } else if (course_grade == "D") {
            gradePoint = 1.0;
        } else if (course_grade == "D-") {
            gradePoint = 0.7;
        } else if (course_grade == "F") {
            gradePoint = 0.0;
        } else {
        cout << "Invalid grade input" << endl;
        return 1;
    }
        courses.emplace_back(course_name, gradePoint); 
    }

    float total_points = 0.0;
    int total_credits = 0;
        
    for (const Course& course : courses) {
    total_points += course.calculate_points();
    total_credits += credits; 
    }
    
    float gpa = total_credits > 0 ? total_points / total_credits : 0.0;
   
    cout << "GPA: " << std::fixed << std::setprecision(2) << gpa << endl;
    
    return 0;
}