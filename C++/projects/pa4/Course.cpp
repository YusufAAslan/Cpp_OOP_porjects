#include <iostream>
#include <string>
#include "Course.h" 
#include "Student.h"


using namespace std;

//default construct
Course::Course()
                :name(""),code("") ,size(0){}

//construc with values
Course::Course(string& name,string& code)
{
    //set name and code
    this->name = name;
    this->code = code;
}



//it's just a destructor that delete obbjects 
Course::~Course()
{
    
    delete [] students;
}

//give name of corse 
string Course::getName() 
{
    return name;
}

//give the course code 
string Course::getCode() 
{
    return code;
}

//set course name 
void Course::setName(const string& name)
{
    this->name = name;
}

//set course code
void Course::setCode(const string& code)
{
    this->code = code;
}

//print and list course's takers by names and ids 
void Course::print()
{
    for(int i=0;i<size;++i)
        cout << i+1 << ". Student" << endl
             << "Name: " << students[i]->getName() << endl
             << "ID: " << students[i]->getID() << endl;
    
}




//add new student to course
void Course::addStudent(Student* student)
{
    if(studentChecker(student)) //check if the student already in the course or not 
    {
        if(size == 0)
        {
            ++size;     //number of students increased 1
            this->students = new Student*[size];    //allocat memory
            this->students[0] = student;    //add student to students array
        }else
        {
            ++size;     //increasing the number of students by one
            Student **temp = new Student*[size];    //allocating memory for temp array for not losing data
            for(int i=0;i<size-1;++i)
                temp[i] = students[i];      //copy students array
            
            temp[size-1] = student;     //then add new student to temp array
            delete [] students;     //now you can delete students array
            students = new Student*[size];      //reallocat memory for new students array after adding new attender
            for(int i=0;i<size;++i)
                students[i] = temp[i];  //copy temp array contents to students array
            delete [] temp;     //delete temp 
        }
    }
}



//just chck if student already taken it or not  by returning 0 if already taken 
bool Course::studentChecker(Student* student)
{
    for(int i=0;i<size;++i)
        if(student->getID()==this->students[i]->getID())
            return 0;
    return 1;
}

//method to delte student drom course 
void Course::deleteStudent(Student* student)
{
    for(int i=0;i<size;++i)
        if(students[i]->getID() == student->getID() && students[i]->getName() == student->getName())
        {
            --size;     //decrementing array size
            Student **temp = new Student*[size];        //allocat memory for temporary array
            for(int j=0;j<size;++j)     //copying all to temp except deleted student
            {
                if(j<i)
                    temp[j] = students[j];
                else if(i<j)
                    temp[j-1] = students[j];
            }
            delete [] students;     //delete students array
            students = temp;        //copy and delete temp array
            delete [] temp ;
        }
}