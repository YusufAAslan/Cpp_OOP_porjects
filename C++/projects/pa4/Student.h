//just class decleratins 
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

class Course;

using namespace std;

class Student
{
    public:
    
        //needed constructors and destructor     
        Student();
        Student(string name,int ID);
        ~Student();


        //getters and setters 


        //get name of student
        string getName() const;
        //get the id
        int getID() const;
        
        //get size of course array
        int getSize() const;

        //set student name
        void setName(string name);
        //set the id
        void setID(int ID);
        //set the size to course array
        void setSize(int size);


        //add student
        void addStudent(Course* course);
        
        //delete course 

        void deleteCourse(Course* course);

        void print();

    private:
        //bool to check if student takes this course or not 
        bool courseChecker(Course* course);
        Course** courses;
        string name;
        int ID;
        int size=0;
};

#endif