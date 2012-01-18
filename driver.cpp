// Kevin Mangan
// Driver program for IntegerSet class
// Computer Science II

#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main(){
	
	// Create objects
	IntegerSet A;
	IntegerSet B;
	IntegerSet C;

	// Fill sets
	cin >> A;
	cout << "\n\t" << A;
	cin >> B;
	cout << "\n\t" << B;

	// Increment and Decrement Test
	cout << "\n\tIncrementing each element in A" << endl;
	A = ++A;
	cout << "\n\t" << A << endl;

	cout << "\n\tDecrementing each element in B" << endl;
	B = --B;
	cout << "\n\t" << B << endl;

	// Mathematical functions
	C = A^B;
	cout << "\n\tThe intersection of Set A and Set B is: ";
	C.printSet();

	C = A+B;
        cout << "\n\tThe union of Set A and Set B is: ";
        C.printSet();

	C = A-B;
        cout << "\n\tThe difference of Set A and Set B is: ";
        C.printSet();

	bool equal = (A==B);
	if(equal)
		cout << "\n\tA and B are equal";

	cout << endl;
}

