#include <iostream>
#include <string>
#include "NumCpp.hpp"

#define WAITKEY (cin.get())

using namespace std;
using namespace numcpp;

int main(void) {
	auto balsal = NumCpp<int>::array({ {1, 2, 3}, {4, 5, 6} });
	auto balsal2 = NumCpp<int>::array({ {1, 2, 3}, {4, 5, 6} });

	auto balsal3 = balsal % balsal2;

	auto bal = NumCpp<int>::array({ 1, 2, 3, 4 });

	bal.push_back(5);
	bal.push_back(100);

	bal.reshape(2, 3).print();


	bal.print();



	WAITKEY;
}