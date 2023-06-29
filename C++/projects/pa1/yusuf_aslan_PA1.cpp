/*To achive Mastermind game I took the guss from user as string then I analyzed it char by char 
to check if it's valid guss or not I have 3 functions one to test the analyze the guss number
random_number to generate the hidden number && get_hint to give user hints  */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


 /* This function to check if te given number is valid or not*/
bool valid_number( string number);



/* This function generate random number as hidden number*/
string random_number(int n);



/* This function gives hints to user to help them guess */
void get_hint(string hidden_number , string user_guess , int Cexact , int Cmisplaced);





int main(int argc, char const *argv[])
{

	/*some variabels used and explaind down*/
	int count = 0;
	string hidden_number;

	int allowed_attempts = 100 ; /* allowed attempts */


	//cout<<"Welcome to Mastermind game please give your guess"<<endl;

	//Erorr checkinggggggggggggggggggg
	/*First check if the compiling args  and calling is true  if not print E0 and exit*/

    if (argc < 2) {
        cout << "E0" << endl;
        return 0;
    }


    if (string(argv[1]) != "-r" && string(argv[1]) != "-u") {
        cout << "E0" << endl;
        return 0;
    }



    if (string(argv[1]) == "-r") {
        if (argc < 3) {
            cout << "E0" << endl;
            return 0;
        }

        int n = atoi(argv[2]);
        if (n <= 0) {
            cout << "E0" << endl;
            return 0;
        }
        hidden_number = random_number(n);
    }

    // If user gives hidden number in calling then use it as hidden_number
    else {
        
        if (argc < 3) {
            cout << "E0" << endl;
            return 0;
        }
        hidden_number = string(argv[2]);
        if (!valid_number(hidden_number)) {
            cout << "E0" << endl;
            return 0;
        }
    }

	/*Aftter checking error do this guess game up to allowed attempts number */
	while (count < allowed_attempts) {
	    string user_guess;
	    cin >> user_guess;


	    if (user_guess.length() != hidden_number.length()){
	        cout << "E1" << endl;
	        return 0 ;
	    }
	    else if (user_guess == hidden_number) {
	        cout << "FOUND " << count + 1<< endl;
	        return 0;
	    }
	    else if (!valid_number(user_guess))
	    {
	    	cout<<"E2"<<endl;
	    }




	    int Cexact = 0;
	    int Cmisplaced = 0;
	    string tmp = hidden_number;

	    for (int i = 0; i < user_guess.length(); i++) {
	        if (user_guess[i] == tmp[i]) {
	            Cexact++;
	            tmp[i] = 'X';
	        }
	    }
	    for (int i = 0; i < user_guess.length(); i++) {
	        if (user_guess[i] != hidden_number[i]) {
	            for (int j = 0; j < hidden_number.length(); j++) {
	                if (user_guess[i] == tmp[j]) {
	                    Cmisplaced++;
	                    tmp[j] = 'X';
	                    break;
	                }
	            }
	        }
	    }
	    cout << Cexact << " " << Cmisplaced << endl;
	    count++;
	}

	/*If user coudlnt guess in given allowed attempts  then print FAILD*/
	cout << "FAILED" << endl;    






	return 0;
}



bool valid_number( string number){
/* This array of boolean values we use it to see if
 number between 0-9 seen or not  so at first we assigned all indexes to false*/
	bool digits_array[10] = {false}; 

	/* the number should be between 0-9 and it cant be 0 at first digit*/
	if (number.length() > 9 || number[0]=='0' )
	{
		return false;
	}


	/* This loop to iterate all digits one by one and check if valid or not for our situation
	 if the number is 123 it will check if 1 & 2 & 3 is seen and uniqe*/
	for (int i = 0; i < number.length(); ++i)
	{

		/* if the given number not an integer return E2 and break*/
		if (!(number[i] >= '0' && number[i] <= '9'))
		{
			cout<<"E2"<<endl;
			break;
		}
		/*Cuz we take numbers as string here we convert them digit by digit from 
		string's char to int digit by subtructing the ascii value of 0 of them */
		int digit = number[i] - '0';

		/*If digits_array [digit] is true thats means already seen so its not valid*/
		if (digits_array[digit])
		{
			return false ;
		}
		else /* digit never seen yet*/
			digits_array[digit] = true;
 

	}


	return true; /*If the number is uniqe after checking return true*/




}


/*generate and return random number as string as secret number*/
string random_number(int n){
  
    string num = "";
    srand(time(NULL));
    num += rand() % 9 + 1 + '0'; /*Dont forget that first digit cannot be 0  and it should be unique number*/
    for (int i = 1; i < n; i++) {
        int digit = rand() % 10;


        /* We need this loop to check every digit is unique or not by iterate all
          and for that I used find () to find the digit and npos  to compare from string lib class*/
        while (num.find(digit + '0') != string::npos) {
            digit = rand() % 10;
        }

        /*if digit is unique then add it to our string */
        num += digit + '0';
    }

    /*return the secert random number as string*/
    return num;

}



/*To give user hints in Mastermind game we should tell them 
how many digits in the correct place and
 how many in wrong place if there is */

void get_hint(string hidden_number , string user_guess , int Cexact , int Cmisplaced){

    Cexact = 0; // at first let both of them 0
    Cmisplaced = 0;
    bool used_digits[10] = { false }; // I used this to keep track of used digits  use and convert to true




    /*This loop to compare hidden number with user number digit by digit*/
    for (int i = 0; i < hidden_number.length(); i++) {


    	/*this if gives how many correct digits */
        if (user_guess[i] == hidden_number[i]) {
            Cexact++;
        }

        /*else mark that digit as used digit after converting it */
        else {


            int digit = hidden_number[i] -'0';
            used_digits[digit] = true;
        }
    }


	/*do liike loop above to check if there is correct digits but misplaced */
    for (int i = 0; i < user_guess.length(); i++) {


        int digit = user_guess[i] -'0';

        /* give the number of misplaced digits after increment*/
        /* if user digit is ture but not equal to the specific digit of hidden number */
        /* make Cmisplaced+1 and turn that used digit to flase*/
        if (used_digits[digit] && user_guess[i] != hidden_number[i]) {
            Cmisplaced++;
            used_digits[digit] = false;
        }
    }

}

