#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

struct Student
{
    string name;
    int id;
    vector<double> assignmentGrades;
    vector<double> examGrades;
    double overallGrade;
};

// Calculate the overall grade for a student
double calculateOverallGrade(const vector<double> &assignmentGrades, const vector<double> &examGrades)
{
    double assignmentAverage = accumulate(assignmentGrades.begin(), assignmentGrades.end(), 0.0) / assignmentGrades.size();
    double examAverage = accumulate(examGrades.begin(), examGrades.end(), 0.0) / examGrades.size();
    return (assignmentAverage * 0.4) + (examAverage * 0.6);
}

// Get data of a new student
void getStudentData(vector<Student> &students)
{
    Student student;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter student ID: ";
    cin >> student.id;

    // Get number of assignments and their grades
    int numAssignments;
    cout << "Enter number of assignments: ";
    cin >> numAssignments;
    cout << "Enter assignment grades: ";
    for (int i = 0; i < numAssignments; ++i)
    {
        double grade;
        cin >> grade;
        student.assignmentGrades.push_back(grade);
    }

    // Get number of exams and their grades
    int numExams;
    cout << "Enter number of exams: ";
    cin >> numExams;
    cout << "Enter exam grades: ";
    for (int i = 0; i < numExams; ++i)
    {
        double grade;
        cin >> grade;
        student.examGrades.push_back(grade);
    }

    // Calculate the overall grade for the student
    student.overallGrade = calculateOverallGrade(student.assignmentGrades, student.examGrades);
    students.push_back(student);
}
void displayStudentData(const vector<Student> &students)
{
    for (const auto &student : students)
    {
        cout << "Name: " << student.name << endl;
        cout << "ID: " << student.id << endl;
        cout << "Overall Grade: " << fixed << setprecision(2) << student.overallGrade << endl;
        cout << endl;
    }
}
void displayClassAverages(const vector<Student> &students)
{
    double totalAssignmentSum = 0;
    double totalExamSum = 0;
    int totalAssignments = 0;
    int totalExams = 0;

    // Sum up all assignments and exam grades
    for (const auto &student : students)
    {
        totalAssignmentSum += accumulate(student.assignmentGrades.begin(), student.assignmentGrades.end(), 0.0);
        totalExamSum += accumulate(student.examGrades.begin(), student.examGrades.end(), 0.0);
        totalAssignments += student.assignmentGrades.size();
        totalExams += student.examGrades.size();
    }

    double assignmentAverage = (totalAssignments > 0) ? totalAssignmentSum / totalAssignments : 0;
    double examAverage = (totalExams > 0) ? totalExamSum / totalExams : 0;
    double overallClassGrade = (assignmentAverage * 0.4) + (examAverage * 0.6);
    // Display averages
    cout << fixed << setprecision(2);
    cout << "CLASS AVERAGE GRADES" << endl;
    cout << "Assignments: " << assignmentAverage << endl;
    cout << "Exams: " << examAverage << endl;
    cout << "Total: " << overallClassGrade << endl;
    cout << endl;
}

bool compareStudents(const Student &a, const Student &b)
{
    return a.overallGrade > b.overallGrade;
}
// Sort and display the top N students
void displayTopStudents(const vector<Student> &students, int topN = 3)
{
    vector<Student> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(), compareStudents);
    cout << "Top " << topN << " Students:" << endl;
    for (int i = 0; i < topN && i < sortedStudents.size(); i++)
    {
        cout << "Name: " << sortedStudents[i].name << endl;
        cout << "ID: " << sortedStudents[i].id << endl;
        cout << "Overall Grade: " << fixed << setprecision(2) << sortedStudents[i].overallGrade << endl;
        cout << endl;
    }
}

int main()
{
    vector<Student> students;
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "Student Grade Management System" << endl;
    cout << "-------------------------------" << endl;
    int choice;
    do
    {
        cout << endl;
        cout << "Choose an option (1,2,3,4,5):" << endl;
        cout << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Display Class Averages" << endl;
        cout << "4. Display Top Students" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl;
            getStudentData(students);
            break;
        case 2:
            cout << endl;
            displayStudentData(students);
            break;
        case 3:
            cout << endl;
            displayClassAverages(students);
            break;
        case 4:
            cout << endl;
            displayTopStudents(students);
            break;
        case 5:
            cout << "EXIT" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
