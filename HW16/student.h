#pragma once

struct Student {
    char* name;
    char* surname;
    char* group;
    int* marks;
    int marksCount;
};

int myStrLen(const char* str);
void myStrCpy(char* dest, const char* src);
void initStudent(Student& student, const char* name, const char* surname, const char* group);
void deleteStudent(Student& student);
void printStudent(const Student& student, int index);
void addStudent(Student*& students, int& count, int& capacity, const Student& newStudent);
void deleteStudentByIndex(Student*& students, int& count, int& capacity, int index);
void editStudentInfo(Student& student, const char* name, const char* surname, const char* group);
void addMark(Student& student, int mark);
void removeMark(Student& student, int markIndex);
void editMark(Student& student, int markIndex, int newMark);
