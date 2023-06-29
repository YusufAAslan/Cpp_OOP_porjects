#include <iostream>
#include <cstdlib>
using namespace std;

// class defintion 
class Vector2D
{

	// x and y 
private:
	int value_of_x;
	int value_of_y;



	// needed constructions and methods  geters and set 
public:
	Vector2D();
	Vector2D( int x_new_Value, int y_new_Value);
	
	int GetX();
	int GetY();
	void set_x_and_y(int x_new_Value, int y_new_Value);	

	 // overload the dot product 
	int operator *(const Vector2D &v2);
	
};


int main(int argc, char const *argv[])
{

	/* given in qustion */



	Vector2D v1(10,0), v2(0,10), v3(10,10), v4(5,4);
	cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()
	<< "," << v2.GetY() << ") = " << v1*v2 << endl;
	cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()
	<< "," << v3.GetY() << ") = " << v2*v3 << endl;
	cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()
	<< "," << v4.GetY() << ") = " << v3*v4 << endl;

	return 0;
}


// defualte constructoor 
Vector2D::Vector2D(){
	value_of_x = 0;
	value_of_y= 0;
}


// paramemtrised constr
Vector2D::Vector2D(int x_new_Value , int y_new_Value){
	value_of_x = x_new_Value ; 

	value_of_y =  y_new_Value ;
}


void Vector2D::set_x_and_y( int x_new_Value, int y_new_Value){


	value_of_x = x_new_Value ; 

	value_of_y =  y_new_Value ;

}



int Vector2D::GetX(){
	return value_of_x;
}


int Vector2D::GetY(){
	return value_of_y;
}


// define what is * operator
int Vector2D::operator *(const Vector2D &v2){

	return (value_of_x*v2.value_of_x) + (value_of_y*v2.value_of_y);
}