/* Hello in this program I wrote 3 header files for 3 classes student and course and the complete manging systm
    every header and class has the neede constructors and destructors and getters and setters and other 
    helper methods I needed it while developing the system  , somtimes  you might find extra cout 
    I put it as a comment I used it for debugging  also you might find some extra lines I needed it 
    for while then I changed my mind ^_^ , in  small words this system to creat new student new course
    by using dynmic array and allocation , also you can delete and add new students and courses

    the system is seperated into 3 files like I mentioned befor .
    I wrote comments as much as I could   thanks for your time and enjoy ^_^ 


*/



#include <iostream>
#include <string>
#include <cstdlib>
#include "SchoolManagerSystem.h"
#include <sstream>// I needed it then my plan didnt work so not used for now -_- 



using namespace std;


// I needed some extra helper functions to make the menu 

// turn sting to int 
int stringToInt(const std::string& str);


//////////////////////////////////////////////////student part helpers
//this for student menu  if user press 1
void StudentMenu(SchoolManagerSystem* school);

// display the selected student  by name and id and his/her menu 
void SelectedStudent(SchoolManagerSystem* school,string name,int ID);



// to add student you have to write name enter id 
//just add student to systm
void addStudent(SchoolManagerSystem* school);


////////////////////////////////////////////////////course part helpers


//course menu display
void CourseMenu(SchoolManagerSystem* school);

//display selected course by name and code and it's menu
void selectedCourse(SchoolManagerSystem* school,string name,string code);

//add course to system
void addCourse(SchoolManagerSystem* school);


int main()
{


// make new array of objects of this system
    SchoolManagerSystem* school = new SchoolManagerSystem;
   


    // display the menu  as it needed
    cout << "Main Menu" << endl;
    do
    {



        int input = 0;
        cout << "0 exit" << endl
             << "1 student" << endl
             << "2 course" << endl
             << "3 list_all_students" << endl
             << "4 list_all_courses" << endl;



            // take the option from user and call the wanted function 
        cin >> input;
        if(input == 1)
        {
            StudentMenu(school);
        }else if(input == 2)
        {
            CourseMenu(school);
        }else if(input == 3)
        {
            school->listAllStudents();
        }else if(input == 4)
        {
            school->listAllCourses();      
        }else if (input==0)
            exit(0);
        
    }while (true);




    
}




/////////////////////////////////////////////////////STUDENT PART

void StudentMenu(SchoolManagerSystem* school)
{
    int input;

    do{
        cout << "0 up" << endl
             << "1 add student" << endl
             << "2 select_student" << endl;
        cin >> input;
        if(input == 1)
        {
            addStudent(school);
        }else if(input == 2 && school->getSSize()!=0)
        {
            string name;
            int ID;
            cout << "Name(whithout space between):";
            cin >> name;
            cout << "ID:";
            cin >> ID;
            if(abs(school->studentChecker(name,ID)))
                SelectedStudent(school,name,ID);
        }
    }while(input!= 0);


    if (input == 0)
    {
        return;
    }
    
}






void SelectedStudent(SchoolManagerSystem* school,string name,int ID)
{

    int input = 0;

    do{
        cout << "0 up" << endl
             << "1 delete_student" << endl
             << "2 list courses" << endl
             << "3 add_selected_student_to_a_course" << endl
             << "4 drop_selected_student_from_a_course" << endl;;
        cin >> input;
        if(input == 1)
        {
            //delete student from systm
            school->deleteStudent(name,ID); 
            return ;
        }else if(input == 3 && school->getCSize() !=0)
        {
            //  list all courses so the user can select
            school->listAllCourses();  
            cin >> input;
            // add student by it its name and id and decrement input which gonna used as an index 
            school->addToACourse(--input,name,ID);
            return ;
        }else if(input == 4 && school->getCSize() !=0)
        {
            //  list all courses
            school->listAllCourses();   
            cin >> input;

            // delete student from course 
            school->dropFromCourse(name,ID,--input);
            return ;


        }


    }while(input!=0);

        // go to main menu 
        if (input==0)
        {
            return;
        }
}

/////////////////////////////////////////////////////////////

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}



/////////////////////////////////////////////////////////////////
// add  student to school object
void addStudent(SchoolManagerSystem* school)
{
    
    // take inputs from user as a line then seperat them  it's not ready yet 
    // int ID;
    // string input, name, id;

    // cin>>input;
    // //getline(cin, input);

    // stringstream ss(input);
    // ss >> name >> id;
    // ID = stringToInt(id);



    string name;
    int ID;

    cout<<"NAME: "<<endl;
    cin >> name;
    cout<<"ID: "<<endl;
    cin >> ID;

    // chcek if there is student with same id or not if not add it 
    if(!(school->addStudent(name,ID)))
    {
        cout << "id is being used by another student." << endl; //just for testing
    }else
    {
        //cout << "Successfully added." << endl;  //just for testing 
    }
}



///////////////////////////////////////////////////////////////// COURSE PART

// course menu 
void CourseMenu(SchoolManagerSystem* school)
{
    int input = 0;
    string code;
    string name;
    do{
        cout << "0 up" << endl
             << "1 add_course" << endl
             << "2 select_course" << endl;
        cin >> input;

         if(input == 1)
        {
            addCourse(school);
        }else if(input == 2)
        {
        
            // Enter  course name and code from the user
            cout << "Course Code and Name:" ;
            cin >> code;
            getline(cin,name,' ');
            getline(cin,name,'\n');
            if(abs(school->courseChecker(name,code)))
                selectedCourse(school,name,code);
            
        }else
        {
            cout << "Invalid Input" << endl; 
            return;
        }
    }while(input!=0);
    if (input==0)
    {
        return;
    }

}




// selected coursse menu and the options 
void selectedCourse(SchoolManagerSystem* school,string name,string code)
{
    int input;
    cout << "0 up" << endl
         << "1 delete_course" << endl
         << "2 list_students_registered_to_the_selected_course" << endl;
    cin >> input;

    if(input == 0)
    {
        //go upper menu
        CourseMenu(school);
    }else if(input == 1)
    {
        //delete wanted corse
        school->deleteCourse(name,code);      
    }else if(input == 2)
    {
        // list all students that takes this course
        school->listCourseStudents(name,code);  
    }else
    {
        cout << "Invalid input" << endl; 
        return ;
    }
}

//add course to school object
void addCourse(SchoolManagerSystem* school)
{
    string code,name;
    //make user give new course's name and code 
    cout << "Course Code and Name:" ;
    cin >> code;
    getline(cin,name,' ');
    getline(cin,name,'\n');


    // check if given course is valid annd not already exist    
    if(school->addCourse(name,code))
    {
        //cout << "Successfully added." << endl;   
    }else
    {
        //cout << "invalid course name or already exist." << endl; 
    }
}

