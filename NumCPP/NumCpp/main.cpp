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

	balsal3.print();


	WAITKEY;
}