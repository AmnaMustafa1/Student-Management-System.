#include <iostream>
#include <string>
#include <vector> // For dynamic array
using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int id;
    string department;
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudentByID(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

int main() {
    vector<Student> students; // Vector to store student records
    int choice;

    while (true) {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add a Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search for a Student by ID\n";
        cout << "4. Update Student Information\n";
        cout << "5. Delete a Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudentByID(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Function to add a new student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newStudent.name);
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    cout << "Enter student department: ";
    cin.ignore();
    getline(cin, newStudent.department);

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\nList of Students:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "Name: " << students[i].name << ", ID: " << students[i].id
             << ", Department: " << students[i].department << "\n";
    }
}

// Function to search for a student by ID
void searchStudentByID(const vector<Student>& students) {
    int id;
    cout << "Enter the student ID to search: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            cout << "Student found:\n";
            cout << "Name: " << students[i].name << ", ID: " << students[i].id
                 << ", Department: " << students[i].department << "\n";
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}

// Function to update student information
void updateStudent(vector<Student>& students) {
    int id;
    cout << "Enter the student ID to update: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            cout << "Enter new name (current: " << students[i].name << "): ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new department (current: " << students[i].department << "): ";
            getline(cin, students[i].department);
            cout << "Student information updated successfully!\n";
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}

// Function to delete a student by ID
void deleteStudent(vector<Student>& students) {
    int id;
    cout << "Enter the student ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
}

