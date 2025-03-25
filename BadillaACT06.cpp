#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Student 
{
    int id;
    string firstName;
    string lastName;
    string course;
    double gpa;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void clearScreen()
{
    system("CLS");
}

void displayMenu() {
    cout << "Welcome to Student Record System!\n";
    cout << "---------------------------------\n";
    cout << "What would you like to do?\n";
    cout << "\nMenu:\n";
    cout << "1) Add Student\n";
    cout << "2) Edit Student\n";
    cout << "3) Delete Student\n";
    cout << "4) View Students\n";
    cout << "5) Exit Program\n";
    cout << "Select an option: ";
}

bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int findStudentIndex(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}

void addStudent() {
    clearScreen();
    if (studentCount >= MAX_STUDENTS) {
        cout << "The Student record currently full at the moment!\n";
        return;
    }

    Student s;
    cout << "Enter Student the ID: ";
    cin >> s.id;

    if (findStudentIndex(s.id) != -1) {
        cout << "The Student ID already exists in our Records.\n";
        return;
    }

    do {
        cout << "Enter the First Name: ";
        cin >> s.firstName;
        if (!isValidName(s.firstName)) cout << "Invalid character in First Name. Please Try again.\n";
    } while (!isValidName(s.firstName));

    do {
        cout << "Enter the Last Name: ";
        cin >> s.lastName;
        if (!isValidName(s.lastName)) cout << "Invalid character in Last Name. Please Try again.\n";
    } while (!isValidName(s.lastName));

    cout << "Enter Course: ";
    cin >> s.course;

    while (true) {
        cout << "Enter the GPA: ";
        cin >> s.gpa;
        if (cin.fail()) {
            cout << "You have not inputed the right GPA! Please Try again.\n";
            cin.clear();
            while (cin.get() != '\n'); 
        } else {
            break; 
        }
    }

    students[studentCount++] = s;
    cout << "The Student you added is successfully in our records!\n";
}

void editStudent() {
    clearScreen();
    int id;
    cout << "Enter Student ID for you to edit: ";
    cin >> id;
    int index = findStudentIndex(id);
    if (index == -1) {
        cout << "Oh no! The Student does not exist!\n";
        return;
    }

    do {
        cout << "Enter your New First Name: ";
        cin >> students[index].firstName;
        if (!isValidName(students[index].firstName)) cout << "Invalid character in First Name. Please Try again.\n";
    } while (!isValidName(students[index].firstName));

    do {
        cout << "Enter your New Last Name: ";
        cin >> students[index].lastName;
        if (!isValidName(students[index].lastName)) cout << "Invalid character in Last Name. Please Try again.\n";
    } while (!isValidName(students[index].lastName));

    cout << "Enter New Course: ";
    cin >> students[index].course;

    while (true) {
        cout << "Enter New GPA: ";
        cin >> students[index].gpa;
        if (cin.fail()) {
            cout << "You have not inputed the right GPA! Please Try again.\n";
            cin.clear();
            while (cin.get() != '\n');
        } else {
            break;
        }
    }

    cout << "The Student record has updated successfully! Hooray!\n";
}

void deleteStudent() {
    clearScreen();
    int id;
    cout << "Enter Student ID would you like to delete: ";
    cin >> id;
    int index = findStudentIndex(id);
    if (index == -1) {
        cout << "Student is already not existing!\n";
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    cout << "The Student deleted successfully!\n";
}

void viewStudents() {
    clearScreen();
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }
    cout << "\nStudent Records:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].firstName << " " << students[i].lastName << ", Course: " << students[i].course << ", GPA: " << students[i].gpa << "\n";
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: viewStudents(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
