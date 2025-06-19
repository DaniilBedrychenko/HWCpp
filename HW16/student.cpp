#include "student.h"
#include <iostream>

using namespace std;

int myStrLen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void myStrCpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void initStudent(Student& student, const char* name, const char* surname, const char* group) {
    int nameLen = myStrLen(name);
    int surnameLen = myStrLen(surname);
    int groupLen = myStrLen(group);

    student.name = new char[nameLen + 1];
    myStrCpy(student.name, name);
    student.surname = new char[surnameLen + 1];
    myStrCpy(student.surname, surname);
    student.group = new char[groupLen + 1];
    myStrCpy(student.group, group);
    student.marks = nullptr;
    student.marksCount = 0;
}

void deleteStudent(Student& student) {
    delete[] student.name;
    delete[] student.surname;
    delete[] student.group;
    delete[] student.marks;
    student.name = nullptr;
    student.surname = nullptr;
    student.group = nullptr;
    student.marks = nullptr;
    student.marksCount = 0;
}

void printStudent(const Student& student, int index) {
    cout << "Student #" << index + 1 << ":\n";
    cout << "Name: " << student.name << "\n";
    cout << "Surname: " << student.surname << "\n";
    cout << "Group: " << student.group << "\n";
    cout << "Marks: ";
    if (student.marksCount == 0) {
        cout << "None";
    } else {
        for (int i = 0; i < student.marksCount; i++) {
            cout << student.marks[i];
            if (i < student.marksCount - 1) cout << ", ";
        }
    }
    cout << "\n------------------------\n";
}

void addStudent(Student*& students, int& count, int& capacity, const Student& newStudent) {
    if (count >= capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        Student* newStudents = new Student[capacity];
        for (int i = 0; i < count; i++) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
    }
    students[count] = newStudent;
    count++;
}

void deleteStudentByIndex(Student*& students, int& count, int& capacity, int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!\n";
        return;
    }
    deleteStudent(students[index]);
    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
}

void editStudentInfo(Student& student, const char* name, const char* surname, const char* group) {
    delete[] student.name;
    delete[] student.surname;
    delete[] student.group;

    int nameLen = myStrLen(name);
    int surnameLen = myStrLen(surname);
    int groupLen = myStrLen(group);

    student.name = new char[nameLen + 1];
    myStrCpy(student.name, name);
    student.surname = new char[surnameLen + 1];
    myStrCpy(student.surname, surname);
    student.group = new char[groupLen + 1];
    myStrCpy(student.group, group);
}

void addMark(Student& student, int mark) {
    int* newMarks = new int[student.marksCount + 1];
    for (int i = 0; i < student.marksCount; i++) {
        newMarks[i] = student.marks[i];
    }
    newMarks[student.marksCount] = mark;
    delete[] student.marks;
    student.marks = newMarks;
    student.marksCount++;
}

void removeMark(Student& student, int markIndex) {
    if (markIndex < 0 || markIndex >= student.marksCount) {
        cout << "Invalid mark index!\n";
        return;
    }
    int* newMarks = new int[student.marksCount - 1];
    for (int i = 0, j = 0; i < student.marksCount; i++) {
        if (i != markIndex) {
            newMarks[j++] = student.marks[i];
        }
    }
    delete[] student.marks;
    student.marks = newMarks;
    student.marksCount--;
}

void editMark(Student& student, int markIndex, int newMark) {
    if (markIndex < 0 || markIndex >= student.marksCount) {
        cout << "Invalid mark index!\n";
        return;
    }
    student.marks[markIndex] = newMark;
}
