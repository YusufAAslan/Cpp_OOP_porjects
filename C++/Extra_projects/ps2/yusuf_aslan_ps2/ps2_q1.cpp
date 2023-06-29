#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



string simulate();



int main(int argc, char const *argv[])
{
	int dualsNmuber = 10000;
	int AaronWin = 0 ;
	int BobWin = 0;
	int CharlieWin = 0;

	for (int i = 0; i < dualsNmuber; ++i)
	{
		string theWinner = simulate();
		if (theWinner == "Aaron")
		{
			AaronWin++;
		}else if (theWinner == "Bob")
		{
			BobWin++;
		}
		else{
			CharlieWin++;
		}
	}

	/*the probabilties*/

	double Aaron_prob = (double) AaronWin/dualsNmuber*100;
	double Bob_prob = (double) BobWin/dualsNmuber*100;
	double Charlie_prob = (double) CharlieWin/dualsNmuber*100;


	/* the outputs */
    cout << "Aaron won " << AaronWin << "/" << dualsNmuber<<" duels or " <<  Aaron_prob<< "%" << endl;
    cout << "Bob won " << BobWin << "/" << dualsNmuber<<" duels or " <<  Bob_prob<< "%" << endl;
    cout << "Charlie won " << CharlieWin << "/" << dualsNmuber<<" duels or " <<  Charlie_prob<< "%" << endl;
	return 0;
}


string simulate(){
	/* we have 3 playes assign them to 1 to 
	show they are alive */
	int Aaron = 1;
	int Bob = 1;
	int Charlie = 1 ;

	int numberOfPlyersStillAlive = 3; /* at first 3 alive*/
	srand(time(0));

	double hit;

	/* we need loop continue till only one player left alive*/
	while(numberOfPlyersStillAlive > 1){

			/*Aaron shoots*/
		if (Aaron ==1)
		{
			hit = (double) rand()/RAND_MAX;
			if (hit < 1.0/3) /*Aaron perfectly hit*/
			{
				Bob = 0; /* Bob is dead and alive players - 1 */
				numberOfPlyersStillAlive--;
			}
			
		}



		if (Bob == 1 && numberOfPlyersStillAlive >1)
		{
			hit = (double) rand() / RAND_MAX;
			if (hit < 1.0/2)
			{
				Charlie = 0 ;
				numberOfPlyersStillAlive--;
			}

		}

		if (Charlie == 1 && numberOfPlyersStillAlive >1)
		{
			Aaron = 0;
			numberOfPlyersStillAlive--;


		}


	}


	if (Aaron== 1 ) /*Aaron woooon*/
	{
		return"Aaron";
	}else if (Bob == 1) /*Bob wooon*/
	{
		return "Bob";
	}
	else{
		return "Charlie";
	}



}

