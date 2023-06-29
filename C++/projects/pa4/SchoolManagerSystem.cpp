#include <stdio.h>
#include "SchoolManagerSystem.h"
#include "Student.h"
#include "Course.h"

using namespace std;



//Constructor
SchoolManagerSystem::SchoolManagerSystem() 
        : courses(NULL), courseSize(0),students(NULL), studentSize(0){}

//Destructor
SchoolManagerSystem::~SchoolManagerSystem()
{
    if(courses!=NULL)
    {
        delete[] courses;
        courseSize = 0;
    }
    if(students!=NULL)
    {
        delete[] students;
        studentSize = 0;
    }
}

//get size of courses array
int SchoolManagerSystem::getCSize() const

{
    return courseSize;
}

//get size of students array
int SchoolManagerSystem::getSSize() const
{
    return studentSize;
}

//list all students
void SchoolManagerSystem::listAllStudents() const
{
    for(int i=0;i<studentSize;++i)
        cout << i+1 << ". Student" << endl 
             << "Name: " << students[i]->getName() << endl
             << "ID: " << students[i]->getID() << endl;
}

//list all courses
void SchoolManagerSystem::listAllCourses() const
{
    for(int i=0;i<courseSize;++i)
        cout << i+1 << ". Course" << endl 
             << "Name: " << courses[i]->getName() << endl
             << "Code: " << courses[i]->getCode() << endl;
}



//add student to the system
bool SchoolManagerSystem::addStudent(string name,int ID)
{
    //checking if there is any students with same ID
    //students can have same name but not samme id 
    if(!(studentIDChecker(ID)))
    {
        //creat new student object
        Student* newStudent = new Student(name,ID);
        if(studentSize == 0)
        {
            //size of array +1 to add
            ++studentSize;
            //dynamic array
            this->students = new Student*[studentSize];
            //push first element
            this->students[0] = newStudent;
        }else
        {

            //size of array +1
            ++studentSize;

            //creat temp array to hold previous data of the  student object array
            Student **temp = new Student*[studentSize];

            //fill temp array
            for(int i=0;i<studentSize-1;++i)
                temp[i] = students[i];
            
            //add new student object to temp
            temp[studentSize-1] = newStudent;
            

            //deleting then recreat  students array
            delete [] students;
            students = new Student*[studentSize];

            //copy temp contents to students array
            for(int i=0;i<studentSize;++i)
                students[i] = temp[i];
           

           // delete tmp
            delete [] temp;
        }
        

        // if new student added successfully reeturn 1
        return 1;
    }
    

    // if the id is taken then return 0
    return 0;
}



// delete student from system
bool SchoolManagerSystem::deleteStudent(string name,int ID)
{
    bool flag = false;

    //check if there is sutdent with that id 
    int i = studentChecker(name,ID);
    if(i==-1){

        //  studenChecker returns -1 when user wants to delete
        //  the student with the index of 0
        i=0;
        flag = true;
    }else if(i>0)
    {
        //  studentChecker returns the index value of student if the student is not the first one
        flag = true;
    }   
 

    if(flag)
    {
        --studentSize;  // number of students -1
        Student **temp = new Student*[studentSize]; //reallocat a tempobarray of students objects
        

        //assign temp array to students array
        
        
            for(int j=0;j<studentSize+1;++j)
            {
                if(j<i)
                    temp[j] = students[j];
                else if(i<j)
                    temp[j-1] = students[j]; 
                else
                {
                    for(int k=0;k<courseSize;++k)
                    {
                        //delete student from every course that he/she took
                        courses[k]->deleteStudent(students[i]);
                    }
                }          
            }

            delete [] students;
            students = temp;    //reassign what was in students array without deleted student 
            
            //return 1 if student deleted succseefully
            return 1;
    }

    //retrn 0 if there is no student with that name and ID
    return 0;
}






//just add course to the system
bool SchoolManagerSystem::addCourse(string name,string code)
{
    if(!courseChecker(name,code))
    {
        if(courseSize == 0)
        {
            ++courseSize;
            this->courses = new Course*[courseSize];
            this->courses[0] = new Course(name,code);
        }else
        {
            ++courseSize;
            Course **temp = new Course*[courseSize];
            for(int i=0;i<courseSize-1;++i)
            {
                temp[i] = courses[i];
            }
            temp[courseSize-1] = new Course(name,code);
            delete [] courses;
            courses = temp;
        }

        return 1;
    }

    return 0;

}

// search and check if just a studen with this details is exist
int SchoolManagerSystem::studentChecker(string name,int ID)
{
    for(int i=0;i<studentSize;++i)
        if(name==this->students[i]->getName() && ID==this->students[i]->getID())
        {
            if(i==0)
            //If the wanted student is index=0 retun -1
                return -1;
            else

                return i;
        } 
  

    //If there are no student with this details then return 0.
    return 0;
}



// check for student with id
bool SchoolManagerSystem::studentIDChecker(int ID)
{
    for(int i=0;i<studentSize;++i)
        if(ID==this->students[i]->getID())
            return 1;
        
    return 0;
}

//chedk for course with name and code
int SchoolManagerSystem::courseChecker(string name,string code)
{
    for(int i=0;i<courseSize;++i)
        if(name==this->courses[i]->getName() && code==this->courses[i]->getCode())
        {
            if(i==0)
            //If the course with index=0 return -1 

                return -1;
            else
            //  If there is a course with that name and ID and the index of
            //  the course is not zero, then returns the index value of the course.
                return i;
        } 
     //  If there are no courses with that name or ID then returns 0.
    return 0;
}

//delete a course from the systm
bool SchoolManagerSystem::deleteCourse(string name,string code)
{
    bool flag = false;
    int i = courseChecker(name,code);
    if(i==-1){
        i=0;
        flag = true;
    }else if(i>0)
        flag = true;
    if(flag)
    {
        --courseSize;
        Course **temp = new Course*[courseSize];
        for(int j=0;j<courseSize+1;++j)
            {
                if(j<i)
                    temp[j] = courses[j];
                else if(i<j)
                    temp[j-1] = courses[j];
                else
                {
                    for(int k=0;k<studentSize;++k)
                    {
                        students[k]->deleteCourse(courses[i]);
                    }
                }
                   
            }
            delete [] courses;
            courses = temp;

            return 1;
    }
    return 0;
}

// Addd student to a course
bool SchoolManagerSystem::addToACourse(int index,string name,int ID)
{
    bool flag = false;

    //  Taking the index value of the student
    int studentNum=studentChecker(name,ID);
    if(studentNum==-1)
    {
        //  studentChecker returns -1 if the student has 
        //  the index value of 0.
        studentNum=0;
        flag = true;
    }else if(studentNum>0 && studentNum<studentSize)
        //  studentNum will be used as the index value of students
        flag = true;
    if(flag)
    {
        if(index>=0 && index<courseSize)
        {
            //  add the course to a student's course array
            this->students[studentNum]->addStudent(courses[index]);
            //  add the stundent to a course's student array
            this->courses[index]->addStudent(students[studentNum]);
        }
    }
    return 0;
}

//list students courses
void SchoolManagerSystem::listStudentCourses(string name,int ID)
{
    int i=studentChecker(name,ID);
    bool flag = false;
    if(i==-1)
    {
        flag = true;
        i = 0;
    }else if(i>0 && i<studentSize)
        flag = true;
    if(flag)
    {
        this->students[i]->print();
    }
}




//list who takes the course
void SchoolManagerSystem::listCourseStudents(string name,string code)
{
    int i=courseChecker(name,code);
    bool flag = false;
    if(i==-1)
    {
        flag = true;
        i = 0;
    }else if(i>0 && i<courseSize)
        flag = true;
    if(flag)
    {
        this->courses[i]->print();
    }
}




//delte student from course
void SchoolManagerSystem::dropFromCourse(string name,int ID,int index)
{
    int i= studentChecker(name,ID);
    if(i==-1)
        i=0;
    students[i]->deleteCourse(courses[index]);
    courses[index]->deleteStudent(students[i]) ;
}

