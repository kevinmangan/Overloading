// Kevin Mangan
// IntegerSet.cpp
// Member function definitions of IntegerSet Class
// Computer Science II
// Overloaded Operator Lab

#include <iostream>
#include "IntegerSet.h"
using namespace std;






// Default Constructor
IntegerSet::IntegerSet(){

	for(int i = 0; i < maxSize; i++)
		set[i] = 0;
}

// Other constructor
IntegerSet::IntegerSet(int intArray[], int arraySize){

	for(int i = 0; i < arraySize; i++){
		if(intArray[i] >= 0 && intArray[i] <= 100){
			int k = intArray[i];
			set[k] = 1;
		}
	}
}

// This function inserts an element into the set one at a time
void IntegerSet::insertElement(int newElement){

	if(newElement >= 0 && newElement <= 99){
                        int k = newElement;
                        set[k] = 1;
	}

}

// This function deletes an element from the set one at a time
void IntegerSet::deleteElement(int newElement){

        if(newElement >= 0 && newElement <= 99){
                        int k = newElement;
                        set[k] = 0;
        }

}

// This funtion inputs a whole set
void IntegerSet::inputSet(){

	int numberOfElements;
	int k;

	cout << "\n\tPlease enter how many elements will be in your set: ";
	cin >> numberOfElements;
	
	if(numberOfElements < 1 || numberOfElements > 100){
		cout << "\n\tNumber not in range" << endl;
		inputSet();
	}
	
	for (int i = 0; i < numberOfElements; i++){
		cout << "\n\tInsert element " << i+1 << ": ";
		cin >> k;
		insertElement(k);
	}
}


// This function will print the set of numbers to the screen
void IntegerSet::printSet(){

	for(int i = 0; i < maxSize; i++){
		if(set[i]==1)
			cout << i << " ";
	}
	
	cout << endl;
	cout << endl;
}


// This function will compute A U B
IntegerSet IntegerSet::unionOf(IntegerSet B){

	IntegerSet t;

	for(int i = 0; i < maxSize; i++){
		if(set[i]==1 || B.set[i]==1)
			t.set[i] = 1;	
	}
	return t;
}


// This function will compute A intersect  B
IntegerSet IntegerSet::intersectionOf(IntegerSet B){

        IntegerSet t;

        for(int i = 0; i < maxSize; i++){
                if(set[i]==1 && B.set[i]==1)
                        t.set[i] = 1;

        }
	return t;
}

// This function will compute A\B
IntegerSet IntegerSet::differenceOf(IntegerSet B){

        IntegerSet t;
	for(int i = 0; i < maxSize; i++)
		t.set[i]=set[i];

        for(int i = 0; i < maxSize; i++){
                if(set[i]==1 && B.set[i]==1)
                        t.set[i] = 0;

        }
	return t;
}


// This function determines if two sets are equal to eachother
bool IntegerSet::isEqualTo(IntegerSet B){

	IntegerSet t;
	bool retstat;	

	int g = 1;

	for ( int i = 0; i < maxSize; i++ ) {
   		 if ( set[i] != B.set[i] ){
      			g = 0;
			break;	
		}
	}

	if(g==0)
		retstat = false;
 
	else 
		retstat = true;

	return(retstat);
}

// Set next placeholder to true for all elements in set
void IntegerSet::increment(){

	bool tempset[maxSize]={0};	

	for(int i = 0; i < maxSize; i++){
                if(set[i]==1){
                        if(i!=maxSize-1){	
				tempset[i+1]=1;
			}
                	else{
				cout << "\n\tIncrementing 100 takes you out of the limit";
				tempset[99] = 1;
			}
				
		}

	}

	for(int i = 0; i < maxSize; i++)
		set[i]=tempset[i];

	
}

// Set previous placeholder true for all elements in set
void IntegerSet::decrement(){

        int tempset[maxSize]={0};

	for(int i = 0; i < maxSize; i++){
                if(set[i]==1){
                        if(i!=0){
                                tempset[i-1]=1;
                        }
                        else{
				cout << "\n\tDecrementing 0 takes you out of the limit";
				tempset[0] = 1;
			}

                }

        }

        for(int i = 0; i < maxSize; i++)
                set[i]=tempset[i];
}

////////////////////////////////////////////////////////
////////////////// Overloaded Functions ////////////////
////////////////////////////////////////////////////////

// Overloaded Equality
bool IntegerSet::operator==(const IntegerSet &B){

	return(this->isEqualTo(B));
}

// Overloaded non-Equality
bool IntegerSet::operator!=(const IntegerSet &B){

	return(!(this->isEqualTo(B)));
}




// Receives this error: In function ‘std::ostream& operator<<(std::ostream&, const IntegerSet&)’:
// IntegerSet.cpp:173: error: base operand of ‘->’ has non-pointer type ‘const IntegerSet’


ostream& operator<<(ostream &o, const IntegerSet &A){

	for(int i = 0; i < A.maxSize; i++){
                if(A.set[i]==1)
                        o << i << " ";
        }

        cout << endl;
        cout << endl;

	return(o);
}


// Overloaded input
istream& operator>>(istream &in, IntegerSet &A){

	A.inputSet();

	return(in);
}


// Overloaded Union
IntegerSet IntegerSet::operator+(IntegerSet &B){
	
	IntegerSet temp = *this;
	return(this->unionOf(B));

}

// Overloaded intersection
IntegerSet IntegerSet::operator^(IntegerSet &B){
        IntegerSet temp = *this;
        return(this->intersectionOf(B));

}

// Overloaded Difference
IntegerSet IntegerSet::operator-(IntegerSet &B){

        IntegerSet temp = *this;
        return(this->differenceOf(B));

}


// Overloaded Pre-increment
IntegerSet& IntegerSet::operator++(){

	this->increment();
	return(*this);
}


// Overloaded Post-increment
IntegerSet& IntegerSet::operator++(int d){

	IntegerSet temp = *this;
	this->increment();

	return(temp);
}


// Overloaded Pre-decrement
IntegerSet& IntegerSet::operator--(){

        this->decrement();
        return(*this);
}



// Overloaded Post-decrement
IntegerSet& IntegerSet::operator--(int d){

        IntegerSet temp = *this;
        this->decrement();

        return(temp);
}

