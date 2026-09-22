#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Course
{
    string name;
    char grade;
    float credit;
    float gradePoint;
};

float getGradePoint(char grade)
{
    switch (grade)
    {
        case 'A':
        case 'a':
            return 10.0;

        case 'B':
        case 'b':
            return 8.0;

        case 'C':
        case 'c':
            return 7.0;

        case 'D':
        case 'd':
            return 6.0;

        case 'E':
        case 'e':
            return 5.0;

        case 'F':
        case 'f':
            return 0.0;

        default:
            return -1.0;
    }
}

int main()
{
    int n;

    cout << "========================================\n";
    cout << "          CGPA CALCULATOR\n";
    cout << "========================================\n";

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of courses.\n";
        return 0;
    }

    Course courses[100];

    float totalCredits = 0.0;
    float totalGradePoints = 0.0;

    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courses[i].name;

        cout << "Enter credit hours: ";
        cin >> courses[i].credit;

        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> courses[i].grade;

        courses[i].gradePoint = getGradePoint(courses[i].grade);

        if (courses[i].gradePoint == -1.0)
        {
            cout << "Invalid grade entered.\n";
            return 0;
        }

        totalCredits += courses[i].credit;
        totalGradePoints += courses[i].gradePoint * courses[i].credit;
    }

    float gpa = totalGradePoints / totalCredits;

    cout << "\n\n========================================\n";
    cout << "             COURSE DETAILS\n";
    cout << "========================================\n";

    cout << left << setw(15) << "Course"
         << setw(10) << "Credit"
         << setw(10) << "Grade"
         << setw(12) << "Grade Point" << endl;

    cout << "----------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << courses[i].name
             << setw(10) << courses[i].credit
             << setw(10) << courses[i].grade
             << setw(12) << courses[i].gradePoint
             << endl;
    }

    cout << "\n========================================\n";
    cout << fixed << setprecision(2);
    cout << "Total Credits       : " << totalCredits << endl;
    cout << "Total Grade Points  : " << totalGradePoints << endl;
    cout << "GPA / CGPA          : " << gpa << endl;
    cout << "========================================\n";

    return 0;
}