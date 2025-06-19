#include "student.h"
#include <iostream>

using namespace std;

int main() {
    Student* students = nullptr;
    int count = 0;
    int capacity = 0;
    int choice;

    do {
        cout << "\nStudent Management Menu:\n";
        cout << "1) Add new student\n";
        cout << "2) Delete student by index\n";
        cout << "3) Edit student info\n";
        cout << "4) Add mark\n";
        cout << "5) Remove mark\n";
        cout << "6) Edit mark\n";
        cout << "7) Show student info\n";
        cout << "8) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                char name[50], surname[50], group[20];
                cout << "Enter name: ";
                cin.getline(name, 50);
                cout << "Enter surname: ";
                cin.getline(surname, 50);
                cout << "Enter group: ";
                cin.getline(group, 20);

                Student newStudent;
                initStudent(newStudent, name, surname, group);
                addStudent(students, count, capacity, newStudent);
                cout << "Student added successfully!\n";
                break;
            }
            case 2: {
                int index;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                deleteStudentByIndex(students, count, capacity, index - 1);
                cout << "Student deleted.\n";
                break;
            }
            case 3: {
                int index;
                char name[50], surname[50], group[20];
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                if (index < 1 || index > count) {
                    cout << "Invalid index!\n";
                    break;
                }
                cout << "Enter new name: ";
                cin.getline(name, 50);
                cout << "Enter new surname: ";
                cin.getline(surname, 50);
                cout << "Enter new group: ";
                cin.getline(group, 20);
                editStudentInfo(students[index - 1], name, surname, group);
                cout << "Student info updated.\n";
                break;
            }
            case 4: {
                int index, mark;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cout << "Enter mark: ";
                cin >> mark;
                cin.ignore();
                if (index < 1 || index > count) {
                    cout << "Invalid index!\n";
                    break;
                }
                addMark(students[index - 1], mark);
                cout << "Mark added.\n";
                break;
            }
            case 5: {
                int index, markIndex;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cout << "Enter mark index (1 to marks count): ";
                cin >> markIndex;
                cin.ignore();
                if (index < 1 || index > count) {
                    cout << "Invalid index!\n";
                    break;
                }
                removeMark(students[index - 1], markIndex - 1);
                cout << "Mark removed.\n";
                break;
            }
            case 6: {
                int index, markIndex, newMark;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cout << "Enter mark index (1 to marks count): ";
                cin >> markIndex;
                cout << "Enter new mark: ";
                cin >> newMark;
                cin.ignore();
                if (index < 1 || index > count) {
                    cout << "Invalid index!\n";
                    break;
                }
                editMark(students[index - 1], markIndex - 1, newMark);
                cout << "Mark updated.\n";
                break;
            }
            case 7: {
                int index;
                cout << "Enter index (1 to " << count << "): ";
                cin >> index;
                cin.ignore();
                if (index < 1 || index > count) {
                    cout << "Invalid index!\n";
                    break;
                }
                printStudent(students[index - 1], index - 1);
                break;
            }
            case 8:
                for (int i = 0; i < count; i++) {
                    deleteStudent(students[i]);
                }
                delete[] students;
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
