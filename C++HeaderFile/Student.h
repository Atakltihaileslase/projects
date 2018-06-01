#include <string>

using namespace std;

class Student {

    // constructor
    Student(string); 
    
    // setters function
    void setId(string);
    void setDepartment(string);
    void setName(string);
    
    // getters function
    string getId();
    string getDepartment();
    string getName();
    
    //a utility function
    void displayStudentInfo();

};
