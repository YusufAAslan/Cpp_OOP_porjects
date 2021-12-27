#include <iostream>
#include  <cstdlib>
#include <time.h>

using namespace std;

/*This function to check if the given number is uniq or not */
int check_if_random_num_uniqe_number(int digit_count);
int check_user_num_if_uniqe(int num,int digits);
void Check_for_numbers_at_same_place_and_different_place(int scrt_number,int usr_number,int digits,int iterations);


int main(int argc, char const *argv[])
{	

	int arg_count = argc;
	int iteration_count = 0;
	int sayici = 0;
	/*Here we convert from argv string to int to know what is the number that user entered And I saved that int in user_integer*/
	char *pNext;
	char *p2next; /*Helper to reconvert from string to int after guessing*/
	int user_integer;
	user_integer = strtol (argv[argc -1], &pNext, 10); // input, ptr to next char in argv (null here),
	//cout<<"user_integer is :	"<<user_integer<<endl;
	char string[user_integer];


	/*This if to check wrong inputs */
	if (arg_count< 3)
	 {
	 	cout<<"E0"<<endl;
	 	exit(0);
	 }
	 
	// cout<<"arg count is :	"<<arg_count<<endl;
	/*///////////////////////////////////////////////////*/


	// /*Here we print what we wrote in command line  as a numbers */
 //   for (int i = 0; i < argc; ++i) 
 //        cout << argv[i] << "\n";
  
	//cout<<"argv              "<<argv[buffer-1][0]<<endl;
	/*Here we look to what user enter if is it r or u*/
	//cout<<"sss	"<<argv[arg_count -2]<<endl;

	 if (arg_count>1)	/*To avoid segmentation falut*/
	 {
	 	
	 
		char user_char_input;		/*This variable to know what user enters*/
		user_char_input = argv[1][1];
		if (argc != 1)
		{
			
			if (user_char_input=='r') /* Thats mean my code will creat random number has diggits equal to user_int*/
			{
				// cout<<"you print r"<<endl;
				if (user_integer <= 0 || user_integer >9)
				{
					cout<<"E0"<<endl;
					exit(0);
				}
				int digits = 1;
				/*This for to know how many digits should be the random number*/
				int counter = 0; /*To count digits number*/
				for (int i = 0; i < user_integer; ++i)
				{
					digits = digits * 10 ;

				}
				
				//////////////
				
				int secret_number = check_if_random_num_uniqe_number(user_integer);
				// cout<<"Your secret number is "<<secret_number<<endl<<endl;
				//////////*/*/*/*/*/*/*/*/
			
				/*Until here we took the secret number now we should take the gusses from user  */
				int user_gusse = 0;
				int allowd_number_of_iteration = 0;
				int temp;	/*Helper used to do operations on user guess number without losing it*/
				int temp1 = 0;	/*Helper used to do operations on secret number without losing it*/
				int temp2 = 0;	/*Helper used to do operations on user guess number without losing it*/		
				bool flag = true;
				do{
					iteration_count++;

					cout<<"pleas enter your gusses"<<endl<<endl;
					/*This string and for to know check if the given number is not int double or other*/
					cin>>string;
					//cout<<string<<endl;
					for (int i = 0; i < user_integer; ++i)
					{
						if (string[i]=='.')
						{
							cout<<"E2"<<endl;
							exit(1);
						}
					}
					user_gusse = strtol (string, &p2next, 10); // input, ptr to next char in argv (null here),

					temp = user_gusse;
					//cout<<"ss"<<temp<<endl;
					check_user_num_if_uniqe(temp,user_integer);
					Check_for_numbers_at_same_place_and_different_place(secret_number,user_gusse,user_integer,iteration_count);
					allowd_number_of_iteration++;
					//cout<<counter<<endl;
			
					}while(allowd_number_of_iteration<100);			/*This should be 100 from pdf */

					/*This if to check the allowed number of iterations was taken*/
					if (allowd_number_of_iteration==100)
					{
						cout<<"FAILD"<<endl;
						exit(1);
					}
					
			}




			else if (user_char_input=='u')
			{

				//cout<<"you print u"<<endl;
				if (user_integer <= 0 )
				{
					cout<<"E0"<<endl;
					exit(0);
				}

				int digits = 1;
				/*This for to know how many digits should be the random number*/
				int counter = 0; /*To count digits number*/
				int tmpp = 0;	/*To make operatipns on user integer without changing it */
				tmpp = user_integer; /*To know how many digit in user number in command line*/
				while (tmpp!=0)
				{
					tmpp = tmpp / 10 ;
					counter++;	

				}
				tmpp = user_integer; /*To make operatipns on user integer without changing it */
				//cout<<"counter:"<<counter;
				//////////////
				check_user_num_if_uniqe(tmpp,counter);
				
				int secret_number = user_integer;
			//	cout<<"Your secret number is "<<secret_number<<endl<<endl;
				//////////*/*/*/*/*/*/*/*/
			
				/*Until here we took the secret number now we should take the gusses from user  */
				int user_gusse = 0;
				int allowd_number_of_iteration = 0;
				int temp;	/*Helper used to do operations on user guess number without losing it*/
				int temp1 = 0;	/*Helper used to do operations on secret number without losing it*/
				int temp2 = 0;	/*Helper used to do operations on user guess number without losing it*/		
				bool flag = true;
				int counter_for_not_int = 0;	/*Helper variable to check if user geuss is not int */
				do{
					iteration_count++;

					cout<<"pleas enter your gusses"<<endl<<endl;
					cin>>string;
					//cout<<string<<endl;
					for (int i = 0; i < user_integer; ++i)
					{
						if (string[i]=='.')
						{
							cout<<"E2"<<endl;
							exit(1);
						}
					}
					user_gusse = strtol (string, &p2next, 10); //convert from string to int,
					int tmp_user_guss = user_gusse;
				 /*This while to check if the int contain any symbols like chars */
					while(tmp_user_guss!=0){
						counter_for_not_int++;
						tmp_user_guss = tmp_user_guss/10;}



					if (counter_for_not_int<counter)
					{
							cout<<"E2"<<endl;
							exit(1);					}

					temp = user_gusse;
					//cout<<temp<<"ss"<<endl;
					check_user_num_if_uniqe(temp,counter);
					Check_for_numbers_at_same_place_and_different_place(secret_number,user_gusse,counter,iteration_count);
					allowd_number_of_iteration++;
					//cout<<counter<<endl;
			
					}while(allowd_number_of_iteration<100);			/*This should be 100 from pdf */

					/*This if to check the allowed number of iterations was taken*/
					if (allowd_number_of_iteration==100)
					{
						cout<<"FAILD"<<endl;
						exit(1);
					}
					



			}
			else
					cout<<"E0"<<endl;
					exit(0);		
		}
		else
					cout<<"E0"<<endl;
					exit(0);	}

	// // //check_if_random_num_uniqe_number(3);
	//Check_for_numbers_at_same_place_and_different_place(123456,123654,6);

	return 0;
}



int check_if_random_num_uniqe_number(int digit_count){
	/*Taking uniqe number and put it in array*/
	int num_arr[digit_count];
  	int counter = 0;
  	int i;
  	int your_num = 0;
  	bool arr[10]={0};
  	time_t t;
  	srand((unsigned)time(&t));
  	for(i=0;i<digit_count;++i)
  	{
    	int r=rand()%9;
   		 if(!arr[r]){
    		num_arr[counter++]=r;
 			}
    	else
      		i--;
    	arr[r]=1;    
  	}
  // 	/*Just for printing */
 	// for (i = 0; i < digit_count; ++i)
 	// {
 	// 	     cout<<num_arr[i]<<endl;

 	// }


 	/*Now we should return it as an int  */
 	int product_cofficent =1; /*This coffecient to know with how much should i multipli array index one by one to gain the correct int number */

 	for ( i = 0; i < digit_count -1; ++i)
 	{
 		product_cofficent = product_cofficent *10;

 	}


 	for ( i = 0; i < digit_count; ++i)
 	{
 		your_num = your_num + num_arr[i]*product_cofficent;
 		product_cofficent= product_cofficent /10;
 	}
 	//cout<<"your num : "<<your_num<<endl;

 	///////////////////////////////////////////////
	return your_num ;
}


/*In this function I check the number given by user is it uniqu or not */
int check_user_num_if_uniqe(int num,int digits){
	int counter = 0;
	int arr[digits];
	int tmp = num; 			/*This one to save number value*/
	while(num!=0){
		arr[counter]=num%10;
		counter++;
		num=num/10;

	}
	//cout<<"counter After :"<<counter;

	/*This for to know if the given number by user is unique or not*/
	for (int i = 0; i < digits; ++i)
	{
		for (int j = 0; j <i ; ++j)
		{
			if ((arr[i]==arr[j]) || (counter!= digits))
			{
				cout<<"E1"<<endl;
				exit(1);
			}
		}
	}
	num = tmp;
	return num;


}

void Check_for_numbers_at_same_place_and_different_place(int scrt_number,int usr_number,int digits,int iterations){
	int scrt_num_arr[digits];
	int usr_number_arr[digits];
	int same_place_counter = 0;
	int exist_but_in_wrong_place = 0;
	int i,j;
	for ( i = 0; i < digits; ++i)
	{
		scrt_num_arr[i] = scrt_number % 10 ;
		usr_number_arr[i] = usr_number % 10 ;
		scrt_number = scrt_number/10;
		usr_number = usr_number /10; 
	}


	for ( i = 0; i < digits; ++i)
	{
		if (scrt_num_arr[i]==usr_number_arr[i])
		{
			same_place_counter++;
		}
		else if(scrt_num_arr[i]!=usr_number_arr[i])
		{
			for ( j = 0; j <digits ; ++j)
			{
				if (scrt_num_arr[i]==usr_number_arr[j])
				{
					exist_but_in_wrong_place++;
				}
		}	}
	}
	cout<<same_place_counter;
	cout<<" "<<exist_but_in_wrong_place<<endl;
	if (same_place_counter == digits)
	{
		cout<<"FOUND 	"<<iterations<<endl;
		exit(1);
	}
	


}