#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

void demonstratePoint() {
    Point p;
    p.x = 5;
    p.y = 10;
    cout << "Point coordinates: (" << p.x << ", " << p.y << ")" << endl;
}

struct Student {
    char name[50];
    int age;
    float averageGrade;
};

void demonstrateStudent() {
    Student s;
    cout << "Enter student name: ";
    cin.getline(s.name, 50);
    cout << "Enter student age: ";
    cin >> s.age;
    cout << "Enter student average grade: ";
    cin >> s.averageGrade;
    cout << "Student Info: Name = " << s.name << ", Age = " << s.age 
         << ", Average Grade = " << s.averageGrade << endl;
    cin.ignore();
}

struct Rectangle {
    float width;
    float height;
};

void demonstrateRectangle() {
    Rectangle r;
    r.width = 4.5;
    r.height = 3.2;
    float area = r.width * r.height;
    cout << "Rectangle Area: " << area << endl;
}

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void demonstrateTime() {
    Time t;
    t.hours = 14;
    t.minutes = 35;
    t.seconds = 20;
    cout << "Time: ";
    if (t.hours < 10) {
        cout << "0";
    }
    cout << t.hours << ":";
    if (t.minutes < 10) {
        cout << "0";
    }
    cout << t.minutes << ":";
    if (t.seconds < 10) {
        cout << "0";
    }
    cout << t.seconds << endl;
}

struct Car {
    char brand[50];
    int year;
    float price;
};

void demonstrateCar() {
    Car c;
    c.brand[0] = 'T'; c.brand[1] = 'o'; c.brand[2] = 'y'; c.brand[3] = 'o'; 
    c.brand[4] = 't'; c.brand[5] = 'a'; c.brand[6] = '\0';
    c.year = 2020;
    c.price = 25000.0;
    cout << "Car Info: Brand = " << c.brand << ", Year = " << c.year 
         << ", Price = $" << c.price << endl;
}

struct Date {
    int day;
    int month;
    int year;
};

void demonstrateDate() {
    Date d;
    d.day = 19;
    d.month = 6;
    d.year = 2025;
    cout << "Date: " << (d.day < 10 ? "0" : "") << d.day << "." 
         << (d.month < 10 ? "0" : "") << d.month << "." << d.year << endl;
}

struct Person {
    char name[50];
    int age;
    float height;
};

void demonstratePerson() {
    Person p;
    cout << "Enter person name: ";
    cin.getline(p.name, 50);
    cout << "Enter person age: ";
    cin >> p.age;
    cout << "Enter person height (in cm): ";
    cin >> p.height;
    cout << "Person Info: Name = " << p.name << ", Age = " << p.age 
         << ", Height = " << p.height << " cm" << endl;
    cin.ignore();
}

struct Book {
    char title[100];
    char author[50];
    int year;
};

void demonstrateBook() {
    Book b;
    b.title[0] = '1'; b.title[1] = '9'; b.title[2] = '8'; b.title[3] = '4'; 
    b.title[4] = '\0';
    b.author[0] = 'G'; b.author[1] = 'e'; b.author[2] = 'o'; b.author[3] = 'r'; 
    b.author[4] = 'g'; b.author[5] = 'e'; b.author[6] = '\0';
    b.year = 1949;
    cout << "Book Info: Title = " << b.title << ", Author = " << b.author 
         << ", Year = " << b.year << endl;
}

struct Employee {
    char name[50];
    char position[50];
    float salary;
};

void demonstrateEmployee() {
    Employee e;
    e.name[0] = 'J'; e.name[1] = 'o'; e.name[2] = 'h'; e.name[3] = 'n'; 
    e.name[4] = '\0';
    e.position[0] = 'M'; e.position[1] = 'a'; e.position[2] = 'n'; 
    e.position[3] = 'a'; e.position[4] = 'g'; e.position[5] = 'e'; 
    e.position[6] = 'r'; e.position[7] = '\0';
    e.salary = 50000.0;
    cout << "Employee Info: Name = " << e.name << ", Position = " << e.position 
         << ", Salary = $" << e.salary << endl;
}

struct Triangle {
    float side1;
    float side2;
    float side3;
};

void demonstrateTriangle() {
    Triangle t;
    t.side1 = 3.0;
    t.side2 = 4.0;
    t.side3 = 5.0;
    
    bool isValid = (t.side1 + t.side2 > t.side3) && 
                   (t.side2 + t.side3 > t.side1) && 
                   (t.side1 + t.side3 > t.side2);
    
    cout << "Triangle with sides " << t.side1 << ", " << t.side2 << ", " 
         << t.side3 << " is " << (isValid ? "valid" : "invalid") << endl;
}

int main() {
    demonstratePoint();
    demonstrateStudent();
    demonstrateRectangle();
    demonstrateTime();
    demonstrateCar();
    demonstrateDate();
    demonstratePerson();
    demonstrateBook();
    demonstrateEmployee();
    demonstrateTriangle();
    return 0;
}
