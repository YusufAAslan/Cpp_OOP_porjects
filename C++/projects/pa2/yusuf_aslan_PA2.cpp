#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;









// Defintion of Image editor calss 

class Image_Editor{

private:


	// Needed variabels and file operations 


	ifstream input;
	ofstream output;

	string input_file_name;
	string output_file_name ;
	
	string img_info;						//This string to hold image information
	string output_string;					//string to hold output information 
	
	vector<int> numercial_values;




public:



	Image_Editor(string  image_file_name);  //Constructors
	Image_Editor(){};

	// Needed member functions
	void read_input_file(string in_file_name); 	// Read image input file
	void write_output_file(string out_file_name); // writing to output file
	void convert_to_grayscale(float c_r,float c_g,float c_b); // convert normal imag to grayscale using given law  
	void menu();// print interactive menu to terminal 


};










int main()
{


	// declare object  of class image editor
	Image_Editor image;

	// call the menu
	image.menu();

  
    return 0;
}








// Helper function convert string to integer we need it while reading from file
int my_stoi(const char *s)			
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


//Define the constractor
Image_Editor::Image_Editor(string image_file_name){  
	
	input_file_name = image_file_name;

}

void Image_Editor::read_input_file(string in_file_name){

	input_file_name = in_file_name;
	input.open(input_file_name.c_str());

	if (!input.is_open())		//Check for wrong inputs if so then exit ..
	{
		exit(-1);
	}

	// helpers
	vector<string> pixel_values; 
	string temp; 

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

	//Copy Image Info
	img_info += pixel_values[0];
	for (int i = 1; i < 5; ++i)
	{
		img_info = img_info + " " + pixel_values[i];
	}
	img_info += " ";

	for (int i = 5; i < pixel_values.size(); ++i)		//start copying after img information and add spaces
	{
		string string_holder = pixel_values[i];

		if (i != pixel_values.size() -1 )
		{
			output_string += " ";
		}

		int place_holder = my_stoi(string_holder.c_str());
		numercial_values.push_back(place_holder);
	}

	input.close();  // close
}

void Image_Editor::convert_to_grayscale(float c_r,float c_g,float c_b){

	output_string = "";
	
	for (int i = 0; i < numercial_values.size(); i = i+3)
	{
		// converrt to grayscale depending on this law gray = (c_r * r + c_g * g + c_b * b)

		int r = numercial_values[i];
        int g = numercial_values[i+1];
        int b = numercial_values[i+2];

        int gray = (int)(c_r * r + c_g * g + c_b * b);

        if (gray > 255) {
        	gray = 255;
        }
         // then assign new values
        numercial_values[i] = gray;
        numercial_values[i+1] = gray;
        numercial_values[i+2] = gray;
    }



        // cout << "Image converted to grayscale" << endl;

	for (int i = 0; i < numercial_values.size(); ++i)
	{
		output_string += to_string(numercial_values[i]) + " ";	// dont forget to add space between the values
	}
}



// just write to output file 
void Image_Editor::write_output_file(string out_file_name){
	
	output_file_name = out_file_name;
	output.open(output_file_name);
	if (output.is_open())
	{
		output<<img_info;
		output<<output_string;	
	}
	
	output.close();
	img_info = "";			// after every save operation reset the strings 
	output_string ="";
}

void Image_Editor::menu(){
	int option,option1;				//Helper variabels
	float c_r = 0.1;		// Start with test inital values for first try befor doing any scripts 
	float c_g=0.1;
	float c_b= 0.1;


	cout<<"MAIN MENU"<<endl;
	cout<<"0 - Exit"<<endl;
	cout<<"1 - Open An Image(D)"<<endl;
	cout<<"2 - Save Image Data(D)"<<endl;
	cout<<"3 - Scripts(D)"<<endl;

	cin>>option;		//user enter option
	switch(option){			
		case 0:
			break;
		case 1:
			cout<<"OPEN AN IMAGE MENU"<<endl;
			cout<<"0 - Up"<<endl;
			cout<<"1 - Enter The Name Of The Image File"<<endl;
			cin>>option1;

			if (option1 == 0)		//if 0 return main menu
			{
				menu();
			}
			else if(option1==1){
			
				string in_file_name;
				cin>>in_file_name;
				read_input_file(in_file_name);
				cout<<"OPEN AN IMAGE MENU"<<endl;
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
				cout<<"SAVE IMAGE DATA MENU"<<endl;
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
			while(option1==1){					//while user pressing 1 hold in this menu
				cout<<"please enter the cofficents"<<endl;
				cin>>c_r>>c_g>>c_b;			
				

				// Check for wrong cofficients inputs 

				    while (c_r < 0 || c_r >= 1 || c_g < 0 || c_g >= 1 || c_b < 0 || c_b >= 1) {
        				cout << "Invalid inputs. Enter 3 float numbers between 0 and 1 please: "<<endl;
        				cin >> c_r >> c_g >> c_b;
    				}


    				// convert if 3 is choosen
				convert_to_grayscale(c_r,c_g,c_b);

				cout<<"CONVERT TO GRAYSCALE MENU"<<endl;
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