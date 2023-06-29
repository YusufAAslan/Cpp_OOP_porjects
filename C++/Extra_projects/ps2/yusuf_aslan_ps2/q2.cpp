#include <iostream>
#include <cstring>

using namespace std;

const int MAX_DIGITS = 20; /* Maximum length of integers in the array*/

int reverse(char a[], int n) ;

void add(char a[], int na, char b[], int nb, char c[], int nc) ;

int main() {





    char a[MAX_DIGITS], b[MAX_DIGITS], c[MAX_DIGITS];
    int na, nb, nc;
    char choice;



    do {

        
        cout << "Enter first integer (up to " << MAX_DIGITS << " digits): ";
        cin >> a;
        cout << "Enter second integer (up to " << MAX_DIGITS << " digits): ";
        cin >> b;

        na = strlen(a);
        nb = strlen(b);
        nc = MAX_DIGITS;

        reverse(a, na);
        reverse(b, nb);
        add(a, na, b, nb, c, nc);
        reverse(c, nc);
       
        cout << "The sum is: " << c << endl;
        cout << "Do you want to continue (y/n)? ";
        cin >> choice;


    } while (choice == 'y' || choice == 'Y');



    return 0;
}



int reverse(char a[], int n) {


    /* This reverses the order of the first n elements of array a*/
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return n;
}



void add(char a[], int na, char b[], int nb, char c[], int nc) {


    /*This adds the first na elements of array a to the first nb elements of array b */
    /* and stores the result in array c, which has size nc */

    int i;
    int carry = 0;

    for (i = 0; i < na && i < nb && i < nc; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        c[i] = (sum % 10) + '0';
        carry = sum / 10;
    }


    while (i < na && i < nc) {
        int sum = (a[i] - '0') + carry;
        c[i] = (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }


    while (i < nb && i < nc) {
        int sum = (b[i] - '0') + carry;
        c[i] = (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }

    if (carry > 0 && i < nc) {
        c[i] = carry + '0';
        i++;
    }

    nc = i;


    if (i == nc && carry > 0) {
        cout << "integer overflow" << endl;
    }
}