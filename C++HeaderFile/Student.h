#include <string>

using namespace std;

class Student {

    // constructor
    Student(string); 

    // setters
    void setId(string);
    void setDepartment(string);
    void setName(string);
    

    // getters
    string getId();
    string getDepartment();
    string getName();
    

    // utility 
    void displayStudentInfo();

};
