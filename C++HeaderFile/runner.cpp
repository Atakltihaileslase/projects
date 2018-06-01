#include <iostream>
#include <Student.h>
using namespace std;

int main() {

    Student student("ATR/0526/08");
    student.setFirstName("Ataklti");
    student.setLastName("Haileslase");
    student.setDepartment("Software Engineering");
    student.setClassYear("seniour");

    student.displayStudentInfo();

}
