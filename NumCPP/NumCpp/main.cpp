#include <iostream>
#include <string>
#include "NumCpp.hpp"

#define WAITKEY (cin.get())

using namespace std;
using namespace numcpp;

int main(void) {
	array1D<int> frontSonarReading;
	array1D<int> leftSonarReading;
	array1D<int> rightSonarReading;

	for (int i = 0; i < 10; i++) {
		frontSonarReading.push_back(i * 10);
		leftSonarReading.push_back(i * 2);
		rightSonarReading.push_back(i * 3);
	}

	array2D<int> bal = NumCpp<int>::array({ {1, 2, 3}, {4, 5, 6} });
	
	auto balchal = array2D<int>::makeSample(leftSonarReading, rightSonarReading, frontSonarReading);


	cout << "Column: " << balchal.getColumn() << endl;
	cout << "Row: " << balchal.getRow() << endl;

	balchal.transpose(true).print();

	balchal.updateSize();

	cout << "Column: " << balchal.getColumn() << endl;
	cout << "Row: " << balchal.getRow() << endl;



	WAITKEY;
}