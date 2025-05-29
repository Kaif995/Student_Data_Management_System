#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int id;
    string name;
    int age;
};

void inputStudentData(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Cannot add more students. Array is full." << endl;
        return;
    }

    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;

    // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number!" << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> s.id`

    cout << "Enter Student Name: ";
    getline(cin, s.name);
    
    cout << "Enter Student Age: ";
    cin >> s.age;
        // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number!" << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> s.age`

    students[count] = s;
    count++;
    cout << "Student added successfully!" << endl;
}

void displayAllStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students to display." << endl;
        return;
    }
    cout << "List of Students:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Student " << (i + 1) << ":" << endl;
        cout << "  ID: " << students[i].id << endl;
        cout << "  Name: " << students[i].name << endl;
        cout << "  Age: " << students[i].age << endl;
    }
}

int findStudentIndexById(const Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}
void editStudent(Student students[], int count) {
    if (count == 0) {
        cout << "No students available to edit." << endl;
        return;
    }
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;
       // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number!" << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> id`
    int index = findStudentIndexById(students, count, id);
    if (index == -1) {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }

    bool editing = true;
    while (editing) {
        cout << "\nEditing student (ID: " << students[index].id << ", Name: " << students[index].name << ", Age: " << students[index].age << ")" << endl;
        cout << "Select field to edit:" << endl;
        cout << "1. Name" << endl;
        cout << "2. Age" << endl;
        cout << "3. Both Name and Age" << endl;
        cout << "4. Cancel / Exit Editing" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // clear newline

        switch(choice) {
            case 1: {
                cout << "Enter new name: ";
                getline(cin, students[index].name);
                cout << "Name updated successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter new age: ";
                cin >> students[index].age;
                cin.ignore(); // clear newline
                cout << "Age updated successfully!" << endl;
                break;
            }
            case 3: {
                cout << "Enter new name: ";
                getline(cin, students[index].name);
                cout << "Enter new age: ";
                cin >> students[index].age;
                cin.ignore(); // clear newline
                cout << "Name and Age updated successfully!" << endl;
                break;
            }
            case 4:
                editing = false;
                cout << "Exiting editing menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please select from 1 to 4." << endl;
        }
    }
}

void deleteStudent(Student students[], int &count) {
    if (count == 0) {
        cout << "No students available to delete." << endl;
        return;
    }
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number!" << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> id`

    int index = findStudentIndexById(students, count, id);
    if (index == -1) {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    cout << "Student deleted successfully!" << endl;
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        cout << "\nStudent Management System Menu" << endl;
        cout << "1. Student Add karna!" << endl;
        cout << "2. Students ka Data display karna!" << endl;
        cout << "3. Student ka Record update karna!" << endl;
        cout << "4. Student Delete karna hy!" << endl;
        cout << "5. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch(choice) {
            case 1:
                inputStudentData(students, studentCount);
                break;
            case 2:
                displayAllStudents(students, studentCount);
                break;
            case 3:
                editStudent(students, studentCount);
                break;
            case 4:
                deleteStudent(students, studentCount);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
