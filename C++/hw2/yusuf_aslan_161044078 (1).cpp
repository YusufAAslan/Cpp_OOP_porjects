#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class image_Editor
{

private:
	ifstream input;
	ofstream output;

	string input_file_name;
	string output_file_name ;
	
	string img_info;						/*This string to hold image information and start reading after them*/
	string output_string;
	
	vector<int> numercial_values;


public:
	void menu();

	image_Editor(string  image_file_name);
	image_Editor(){};
	void read_input_file(string in_file_name); 	/*This function to read input file starting after img information*/
	void write_output_file(string out_file_name); /*For writing to output file*/
	void convert_to_grayscale(float c_r,float c_g,float c_b); /*This function to to convert normal img to grayscale*/


};


int my_stoi(const char *s)			/*Helper function to convert from string to integer*/
{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}
//------------------------------------------------------------------> MAIN
int main()
{
	string file_name;
	image_Editor img1;
	img1.menu();

  
    return 0;
}

image_Editor::image_Editor(string image_file_name){ /*img editor class constractor */
	
	input_file_name = image_file_name;

}

void image_Editor::read_input_file(string in_file_name){

	input_file_name = in_file_name;
	input.open(input_file_name.c_str());

	if (!input.is_open())		/*If user enters somthing worng in place of input file name end the program*/
	{
		exit(-1);
	}

	vector<string> pixel_values; 
	string temp; /*helper string*/

	char ch;

	while(input.get(ch)){
		if ( ch != '\n' && ch != ' ' && ch != '\t')
		{
			temp += ch; 
			
		}
		else{

			pixel_values.push_back(temp);
			temp = "";
		}	
	}

//Copy Image Info--------------------------------------.
	img_info += pixel_values[0];
	for (int i = 1; i < 5; ++i)
	{
		img_info = img_info + " " + pixel_values[i];
	}
	img_info += " ";
//------------------------------------------------------

	for (int i = 5; i < pixel_values.size(); ++i)		/*start copying after img informaion with putting spaces*/
	{
		string string_holder = pixel_values[i];

		if (i != pixel_values.size() -1 )
		{
			output_string += " ";
		}

		int place_holder = my_stoi(string_holder.c_str());
		numercial_values.push_back(place_holder);
	}

	input.close();
}

void image_Editor::convert_to_grayscale(float c_r,float c_g,float c_b){

	output_string = "";
	
	for (int i = 0; i < numercial_values.size(); i = i+3)
	{
		numercial_values[i]   = (c_r * numercial_values[i]) + (c_g * numercial_values[i+1]) + (c_b * numercial_values[i+2]);
		numercial_values[i+1] = (c_r * numercial_values[i]) + (c_g * numercial_values[i+1]) + (c_b * numercial_values[i+2]);
		numercial_values[i+2] = (c_r * numercial_values[i]) + (c_g * numercial_values[i+1]) + (c_b * numercial_values[i+2]); 

		if (numercial_values[i] > 255)	/*if the resulte bigger than 255 as said in pdf*/
		{
			numercial_values[i] = 255;
			numercial_values[i+1] = 255;
			numercial_values[i+2] = 255;
		}
	}
	for (int i = 0; i < numercial_values.size(); ++i)
	{
		output_string += to_string(numercial_values[i]) + " ";	/*putting on space between  the values*/
	}
}

void image_Editor::write_output_file(string out_file_name){
	
	output_file_name = out_file_name;
	output.open(output_file_name);
	if (output.is_open())
	{
		output<<img_info;
		output<<output_string;	
	}
	
	output.close();
	img_info = "";			/*reset our strings after saving each photo*/
	output_string ="";
}

void image_Editor::menu(){
	int option,option1;				/*Helper variabels to make our menu*/
	float c_r = 0.1;		/*putting intiale value for first try befor doing any scripts */
	float c_g=0.1;
	float c_b= 0.1;


	cout<<"MAIN MENU"<<endl;
	cout<<"0 - Exit"<<endl;
	cout<<"1 - Open An Image(D)"<<endl;
	cout<<"2 - Save Image Data(D)"<<endl;
	cout<<"3 - Scripts(D)"<<endl;

	cin>>option;		/*taking user's option*/
	switch(option){			/*This cases were done according to  pdf steps*/
		case 0:
			break;
		case 1:
			cout<<"OPEN AN IMAGE MENU"<<endl;
			cout<<"0 - Up"<<endl;
			cout<<"1 - Enter The Name Of The Image File"<<endl;
			cin>>option1;

			if (option1 == 0)		/*if user enter 0 go back to main menu*/
			{
				menu();
			}
			else if(option1==1){
			
				string in_file_name;
				cin>>in_file_name;
				read_input_file(in_file_name);
				cout<<"0 - Up"<<endl;
				cout<<"1 - Enter The Name Of The Image File"<<endl;
				cin>>option1;
				if(option1==0){
					menu();
				}
			}
			break;
		case 2:
			cout<<"SAVE IMAGE DATA MENU"<<endl;
			cout<<"0 - Up"<<endl;
			cout<<"1 - Enter a file name"<<endl;
			cin>>option1;

			if (option1 == 0)
			{
				menu();
			}
			else if(option1==1){
			
				string out_file_name;
				cin>>out_file_name;
				
				write_output_file(out_file_name);

				cout<<"0 - Up"<<endl;
				cout<<"1 - Enter a file_name"<<endl;
				cin>>option1;
				if(option1==0){
					menu();
				}				
			}			
			break;
		case 3 :
			cout<<"CONVERT TO GRAYSCALE MENU"<<endl;
			cout<<"0 - Up"<<endl;
			cout<<"1 - Convert To Grayscale(D)"<<endl;
			cin>>option1;
			if (option1 == 0)
			{
				menu();
			}
			while(option1==1){					/*while user pressing 1 stay in this menu*/
				cout<<"please enter the cofficents"<<endl;
				cin>>c_r>>c_g>>c_b;			

				convert_to_grayscale(c_r,c_g,c_b);

				cout<<"0 - Up"<<endl;
				cout<<"1 - Convert To Grayscale(D)"<<endl;
				cin>>option1;
				if(option1==0){
					menu();
				}				
			}		
			break;		
			
	}
}