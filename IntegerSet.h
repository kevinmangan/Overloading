// Kevin Mangan
// IntegerSet.h
// Declaration of IntegerSet Class
// Overloaded Operators Lab

#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <iostream>
using namespace std;

class IntegerSet{

	public:
		// Constructors
		IntegerSet();
		IntegerSet(int[], int);
		
		// Original Set Operations
		IntegerSet unionOf(IntegerSet);
		IntegerSet intersectionOf(IntegerSet);
		IntegerSet differenceOf(IntegerSet);
		void insertElement(int);
		void deleteElement(int);
		void inputSet();
		void printSet();
		bool isEqualTo(IntegerSet);
		void increment();
		void decrement();


		// Overloaded Functions
		bool operator==(const IntegerSet&);
		bool operator!=(const IntegerSet&);
		friend ostream& operator<<(ostream&, const IntegerSet&);
		friend istream& operator>>(istream&, IntegerSet&);
		IntegerSet operator+(IntegerSet&);
		IntegerSet operator^(IntegerSet&);
		IntegerSet operator-(IntegerSet&);
		IntegerSet& operator++();
		IntegerSet& operator++(int);
		IntegerSet& operator--();
		IntegerSet& operator--(int);

	private:
		static const int maxSize = 100;
		bool set[maxSize];
};



#endif
