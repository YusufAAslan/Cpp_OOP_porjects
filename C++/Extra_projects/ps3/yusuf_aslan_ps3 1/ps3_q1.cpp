#include <iostream>
using namespace std ;

class HotDogStand{
private:
	int hotDogStand_Id;
	int soldToday_count = 0 ;
	static int totalSold_hotdogs ; 
public:

	HotDogStand(int id , int sold_hotdogs){
		hotDogStand_Id = id ; 
		soldToday_count  = sold_hotdogs;

	}
	void JustSold(){
		soldToday_count++;
		totalSold_hotdogs++;

	}
	int  numberOfHotdogsSold_today(){
		return soldToday_count;
	}
	static int total_sold_number_of_all_stands(){
		return totalSold_hotdogs;
	}




};


int HotDogStand::totalSold_hotdogs = 0 ;

int main(int argc, char const *argv[])
{
	/* test our class for many stands */
	HotDogStand stand1(1,0); /* 0 hotdog has been sold yet */
	HotDogStand stand2(2,0); /* 0 hotdogs has been sold yet */
	HotDogStand stand3(3,0); /* 0 hotdogs has been sold  yet */


	stand1.JustSold(); 

	stand2.JustSold(); 
	stand2.JustSold(); 


	stand3.JustSold();
	stand3.JustSold();
	stand3.JustSold(); 


	cout<< "Stand1 has "<<stand1.numberOfHotdogsSold_today()<<" hotdogs sold today"<<endl;
	cout<< "Stand2 has "<<stand2.numberOfHotdogsSold_today()<<" hotdogs sold today"<<endl;
	cout<< "Stand3 has "<<stand3.numberOfHotdogsSold_today()<<" hotdogs sold today"<<endl;


	cout<< "all stands has this number sold   "<<HotDogStand::total_sold_number_of_all_stands()<<" of hotdogs"<<endl;
	
	return 0;
}
