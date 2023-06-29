// here is the implimentation of Student class

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"


using namespace std;




//assign the default Consstructor
Student::Student() : name(""), ID(0),courses(NULL){}

//constructor with values 
Student::Student( string name, int ID)
{
    this->name = name;
    this->ID = ID;
    this->size = 0;
}

//destrucotr to destruct the object 
Student::~Student()
{
    delete [] courses;
    size = 0;
}

//set student name 
void Student::setName(string name)
{
    this->name = name;
}


//set student id 
void Student::setID(int ID)
{
    this->ID = ID;
}



//get student name 
string Student::getName() const
{
    return name;
}

//get student id
int Student::getID() const
{
    return ID;
}

//get coures array size 
int Student::getSize() const
{
    return size;
}

//set size to course array
void Student::setSize(int size)
{
    this->size = size;
}

//print whatever the courses that taken by the student 
void Student::print()
{
    for(int i=0;i<size;++i)
        cout << i+1 << ". Course" << endl
             << "Name:" << courses[i]->getName() << endl
             << "Code:" << courses[i]->getCode() << endl;
}



//add new course to that student
void Student::addStudent(Course* course)
{
    //chcek if this course taken already
    if(courseChecker(course))   
    {
        if(size == 0)
        {
            ++size;     //add 1 to array size        
            this->courses = new Course*[size];      //creat memory and   Allocat 
            this->courses[0] = course;      //add the first element of courses
        }else
        {
            ++size;     // increment array size
            Course **temp = new Course*[size];      //creat memory for temp array
            for(int i=0;i<size-1;++i)
                temp[i] = courses[i];   //keep the vlaue in temp to not be losed
                     
            temp[size-1] = course;    // add new element to temp
            delete [] courses;  //delete cours array
            courses = new Course*[size];    //reallocat memory for courses array
            for(int i=0;i<size;++i)     //assign the values of courses
                courses[i] = temp[i];
            delete [] temp;     //delete temp array
        }
    }
}




bool Student::courseChecker(Course* course)
{
    // if student already taken this course then return 0  if not retrun 1
    for(int i=0;i<size;++i)
        if(course->getCode()==this->courses[i]->getCode() && course->getName()==this->courses[i]->getName() )
            return 0;
    return 1;
}





//delete student from specfic course by using delete and new 
void Student::deleteCourse(Course* course)
{
    for(int i=0;i<size;++i)
        if(courses[i]->getName() ==  course->getName() && courses[i]->getCode() == course->getCode())
        {
            --size;     //student's array size -1
            Course **temp = new Course*[size];      //creat memory to temp course pointer array
            for(int j=0;j<size+1;++j)       //copy courses array to temp
            {
                if(j<i)
                    temp[j] = courses[j];
                else if(i<j)
                    temp[j-1] = courses[j];
            }
            delete [] courses;      //now delete courses array
            courses = temp;     //now copy temp array to courses array
            delete [] temp ;        //at the end delete temp array
        }

}