#include <iostream>
#include <vector>
using namespace std ;


int findLuckyWinner(int n);

int main(int argc, char const *argv[])
{
	int n = 0;
	cout<<"please enter the nummber you want to test :"<<endl;
	cin>>n;
	cout<<"The lucky one is "<<findLuckyWinner(n)<<"  !!!!!"<<endl;
	return 0;
}


int findLuckyWinner(int n){

	/*we need vector */
	vector<int> sutors(n);

	/* here we need loop to assign the nummbers to sutors vector*/

	for (int i = 0; i < n; ++i)
	{
		sutors[i]= i + 1;
	}



	/*Now after elimnating the 3. one so we need to start from index 2 */
	int index = 2;
	while(sutors.size() > 1){
		sutors.erase(sutors.begin() + index);
		index = (index + 2) % sutors.size();
	}

	/*so now after deleteing all the nonluckyy ones return the lucky*/
	return sutors[0];

}

