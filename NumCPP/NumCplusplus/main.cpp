
#include <NumCpp.hpp>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	
	array1D<int> abal1 = NumCpp<int>::array({1, 2, 3, 4});
	array1D<int> abal2 = NumCpp<int>::array({1, 2, 3, 4});
	array1D<int> abal3 = NumCpp<int>::array({1, 2, 3, 4});
	
	auto abal = NumCpp<int>::concatenate(abal1, abal2, abal3);
	abal.print();
	
	
	
	return 0;
}