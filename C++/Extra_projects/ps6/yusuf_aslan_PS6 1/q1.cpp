#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray {
private:



    string* dynamicArray;
    int size;




public:



    //constructor
    DynamicStringArray() {
        dynamicArray = NULL;
        size = 0;
    }



    //Destructor
    ~DynamicStringArray() {
        delete[] dynamicArray;
    }



    //Copy constructor
    DynamicStringArray(const DynamicStringArray& other) {
        size = other.size;
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++) {
            dynamicArray[i] = other.dynamicArray[i];
        }
    }



    //Asignment op 
    DynamicStringArray& operator=(const DynamicStringArray& other) {
        if (this != &other) {
            delete[] dynamicArray;
            size = other.size;
            dynamicArray = new string[size];
            for (int i = 0; i < size; i++) {
                dynamicArray[i] = other.dynamicArray[i];
            }
        }
        return *this;
    }



    //Getter gives the size of the array 
    int getSize() const {
        return size;
    }



    //Add entry to the array
    void addEntry(const string& entry) {
        string* newArray = new string[size + 1];
        for (int i = 0; i < size; i++) {
            newArray[i] = dynamicArray[i];
        }
        newArray[size] = entry;
        size++;
        delete[] dynamicArray;
        dynamicArray = newArray;
    }



    //Delete 
    bool deleteEntry(const string& entry) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (dynamicArray[i] == entry) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        }
        string* newArray = new string[size - 1];
        for (int i = 0; i < index; i++) {
            newArray[i] = dynamicArray[i];
        }
        for (int i = index + 1; i < size; i++) {
            newArray[i - 1] = dynamicArray[i];
        }
        size--;
        delete[] dynamicArray;
        dynamicArray = newArray;
        return true;
    }



    //Get entry from the array
    string getEntry(int index) const {
        if (index < 0 || index >= size) {
            return "";
        }
        return dynamicArray[index];
    }



};




int main()
{



	DynamicStringArray names;
	// List of names
	names.addEntry("Frank");
	names.addEntry("Wiggum");
	names.addEntry("Nahasapeemapetilon");
	names.addEntry("Quimby");
	names.addEntry("Flanders");
	// Output list
	cout << "List of names:" << endl;


	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	// Add and remove some names
	names.addEntry("Spuckler");
	cout << "After adding a name:" << endl;


	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.deleteEntry("Nahasapeemapetilon");
	cout << "After removing a name:" << endl;


	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.deleteEntry("Skinner");

	cout << "After removing a name that isn't on the list:" << endl;

	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.addEntry("Muntz");
	cout << "After adding another name:" << endl;


	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;


	// Remove all of the names by repeatedly deleting the last one
	while (names.getSize() > 0) {
		names.deleteEntry(names.getEntry(names.getSize() - 1));
	}
	cout << "After removing all of the names:" << endl;


	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	names.addEntry("Burns");
	cout << "After adding a name:" << endl;


	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;
	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	// Remove Burns from names
	names.deleteEntry("Burns");
	cout << "Copied names:" << endl;


	for (int i = 0; i < names2.getSize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;
	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	// Remove Burns from names2
	names2.deleteEntry("Burns");
	cout << "Copied names:" << endl;

	for (int i = 0; i < names3.getSize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;
	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;


	return 0;
}