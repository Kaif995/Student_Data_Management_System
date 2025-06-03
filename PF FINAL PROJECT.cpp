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
        cout << " Students Mazeed Add Nhi Ho Sakte . Array Full Ho Chuka Hai. " << endl;
        return;
    }

    Student s;
    cout << " Student ID Bata De: ";
    cin >> s.id;

    // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Ap ka Input Galat Hai. Number Enter Karay! " << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> s.id`

    cout << " Student Ka Naam Bata De: ";
    getline(cin, s.name);
    
    cout << " Student Ki Age Bata De: ";
    cin >> s.age;
        // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Ap ka Input Galat Hai. Number Enter Karay! " << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> s.age`

    students[count] = s;
    count++;
    cout << " Student Add Ho Gaya Hai! " << endl; //add ho choka hai
}

void displayAllStudents(const Student students[], int count) {
    if (count == 0) {
        cout << " Koi Student Add Nhi Hai Display Ke Liye. " << endl;
        return;
    }
    cout << " Sarry Students: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "Student " << (i + 1) << ":" << endl;
        cout << "  ID: " << students[i].id << endl;
        cout << "  Naam: " << students[i].name << endl;
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
        cout << " Koi Student Available Nhi Hai Edit Ke Liye." << endl;
        return;
    }
    int id;
    cout << " Select karay Student ID Edit Ke Liye: ";
    cin >> id;
       // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Ap ka Input Galat Hai. Number Enter Karay! " << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> id`
    int index = findStudentIndexById(students, count, id);
    if (index == -1) {
        cout << " Ye Student ID " << id << " Nhi Hai." << endl;
        return;
    }

    bool editing = true;
    while (editing) {
        cout << " \n Editing student (ID: " << students[index].id << ", Naam: " << students[index].name << ", Age: " << students[index].age << ")" << endl;
        cout << " Field Select Karay Edit karnay ke liye: " << endl;
        cout << " 1. Naam " << endl;
        cout << " 2. Age " << endl;
        cout << " 3. Ya Phir Naam or Age Dono " << endl;
        cout << " 4. Cancel Or Exit Karay Editing " << endl;
        cout << " Select Karay 1 se 4 Ke Darmiyan: ";
        int choice;
        cin >> choice;
        cin.ignore(); // clear newline

        switch(choice) {
            case 1: {
                cout << " Naam Bata de: ";
                getline(cin, students[index].name);
                cout << " Naam update Ho Gaya Hai! " << endl;
                break;
            }
            case 2: {
                cout << " Age Bata de: ";
                cin >> students[index].age;
                cin.ignore(); // clear newline
                cout << " Age update Ho Gaya Hai! " << endl;
                break;
            }
            case 3: {
                cout << " Naam Bata de: ";
                getline(cin, students[index].name);
                cout << " Age Bata de: ";
                cin >> students[index].age;
                cin.ignore(); // clear newline
                cout << " Naam or Age Dono update Ho Gaay Hai! " << endl;
                break;
            }
            case 4:
                editing = false;
                cout << " Exiting Editing Menu. " << endl;
                break;
            default:
                cout << " Ap Ki Choice Galat Hai. Select Karay 1 se 4 Ke Darmiyan. " << endl;
        }
    }
}

void deleteStudent(Student students[], int &count) {
    if (count == 0) {
        cout << " Koi Student Available Nhi Hai Delete Ke Liye. " << endl;
        return;
    }
    int id;
    cout << " Select Karay Student ID Ko delete ke liye: ";
    cin >> id;
    // Validate input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Ap ka Input Galat Hai. Number Enter Karay! " << endl;
        return;  // Exit function instead of using `continue`
    }

    cin.ignore(); // Clear newline left by `cin >> id`

    int index = findStudentIndexById(students, count, id);
    if (index == -1) {
        cout << " Ye Student ID " << id << " Nhi Hai. " << endl;
        return;
    }

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    cout << " Student Delete Ho Gaya Hai! " << endl;
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        cout << " \n Student Management System Menu " << endl;
        cout << " 1. Kiya Ap Ko Student Add karna Hai! " << endl;
        cout << " 2. Kiya Ap ko Students ka Data dekhna Hai! " << endl;
        cout << " 3. Kiya Ap Student ka Record update karna chathy hai! " << endl;
        cout << " 4. Kiya Ap ko Student Delete karna Hai! " << endl;
        cout << " 5. Ya Phir Exit karna chathy hai ! " << endl;
        cout << " Select Karay 1 se 5 Ke Darmiyan: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Ap Ka Input Galat Hai. Number Enter Karay 1 se 5 Ke Darmiyan: " << endl;
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
                cout << " Exiting program. Allah Hafiz! " << endl;
                break;
            default:
                cout << " Ap ki Choice Galat Hai. Select Karay 1 se 5 Ke Darmiyan: " << endl;
        }
    } while (choice != 5);

    return 0;
}
