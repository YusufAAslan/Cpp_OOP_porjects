//just class decleratins 

#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>

class Student;
using namespace std;

class Course
{
    public:
    
       // needed constructors and destructors     
        Course();
        Course(string& name,string& code);
        ~Course();

        // needed getters and setters for name code 
        string getName() ;
        string getCode() ;

        void setName(const string& name);
        void setCode(const string& code);

        // other needed methods for course class
        void print();
        void addStudent(Student* student);
        void deleteStudent(Student* student);

    private:

        bool studentChecker(Student* student);
    
        //dynamically allocate an array of Student objects.
        Student** students;
        string name;
        string code;
        int size=0;
};

#endif