#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class Student
{
	public:
	

	Student();  // con 
	~Student();	// destructor
	void InputData(); // take all values from USER
	void OutputData(); // print out the name and list all courses
	void ResetClasses(); 
	Student& operator =(const Student& rightSide);  // overload assignment operator
	


	private:
		// member variabels 
	string name;
	int numClasses;
	string *classList;


};






int main()
{

	// From the pdf

	
	Student s1, s2;
	s1.InputData(); // Input data for student 1
	cout << "Student 1's data:" << endl;
	s1.OutputData(); // Output data for student 1
	cout << endl;
	s2 = s1;
	cout << "Student 2's data after assignment from student 1:" << endl;
	s2.OutputData(); // Should output same data as for student 1
	s1.ResetClasses();
	cout << "Student 1's data after reset:" << endl;
	s1.OutputData(); // Should have no classes
	cout << "Student 2's data, should still have original classes:" << endl;
	s2.OutputData(); // Should still have original classes
	cout << endl;
	return 0;
}


// constructor 

Student::Student()
{
	numClasses = 0;
	classList = NULL;
	name = "";
}


// Destructor 
Student::~Student()
{
	if (classList != NULL)
	{
		delete [] classList;
	}
}



// Take inputs 
void Student::InputData()
{
	int i;

	ResetClasses();
	cout << "Enter student name." << endl;
	getline(cin, name);
	cout << "Enter number of classes." << endl;
	cin >> numClasses;
	cin.ignore(2,'\n'); // Discard extra newline
	if (numClasses > 0)
	{

		classList = new string[numClasses];// iterate over the number of clases
		// assign every name to our dynmic array


		for (i=0; i<numClasses; i++)
		{
			cout << "Enter name of class " << (i+1) << endl;
			getline(cin, classList[i]);
		}
	
	}

	cout << endl;


}


// print all 

void Student::OutputData(){
	int i;
	cout << "Name: " << name << endl;
	cout << "Number of classes: " << numClasses << endl;
	for (i=0; i<numClasses; i++)
	{
	cout << " Class " << (i+1) << ":" << classList[i] << endl;
	}
	cout << endl;
}




// reset classes


void Student::ResetClasses()
{
	if (classList != NULL)
	{
		delete [] classList;
		classList = NULL;
	}
	numClasses = 0;
}





// operator overload 

Student& Student::operator =(const Student& rightSide)
{
	int i;
	ResetClasses(); // Erase list of classes
	name = rightSide.name;
	numClasses = rightSide.numClasses;
	// Copy the list of classes
	if (numClasses > 0)
	{
		classList = new string[numClasses];


		for (i=0; i<numClasses; i++)
		{
			classList[i] = rightSide.classList[i];
		}

	}

	return *this;
}