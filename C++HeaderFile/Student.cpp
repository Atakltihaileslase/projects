#include <iostream>
#include "Student.h"
using namespace std;

// this below list is a constructor
void Student::Student(string stuId) {
    setId(stuId);
}

// these below listed functions are setters
void Student::setId(string stuId) {
    id = stuId;
}
void Student::setName(string fullname) {
            name = fullname;
}
void Student::setDepartment(string dep) {
    department = dep;
}

// these below listed functions are setters getters
string Student::getId() {
    return id;
}
string Student::getName() {
    return name;
}
string Student::getDepartment() {
    return department;
}

// this ia a utility function
void Student::displayStudentInfo() {
    cout<<"Student Id: "<<getId()<<endl;
    cout<<"Full name: "<<getName()<<endl;
    cout<<"Department: "<<getDepartment()<<endl;
}

