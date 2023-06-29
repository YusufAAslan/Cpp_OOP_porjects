#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

#define max 50

class MyInteger
{
	public:
	MyInteger(int num);

	void set(int new_num);	

	int getnum();
	int operator[](int index);
	private:
	int num;
	int a[max];
};






int main()
{ 
	// Some test numbers
	MyInteger num(25);
	cout << num[0] << " " << num[1] << " " << num[2] << endl;
	cout << num[3] << endl;
	cout << num[-1] << endl;
	return 0;
}


MyInteger::MyInteger(int num){
	this->num = num;
}

void MyInteger::set(int new_num){
	num = new_num;
}	

int MyInteger:: getnum(){
	return num;
}





int MyInteger::operator[](int index)
{
	int tmp;

	if (index <0)
	{
		cout<<"illegal index"<<endl;
		return -1 ;
	}
	else{
		
		tmp = (int) (num / (pow(10,index)));
		// right most is the answer
		if (tmp == 0)
		{
			return -1 ;
		}
		return (tmp %10);

	}
	 
}