
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	
	array1D<int> a = NumCpp<int>::array({1, 2, 3});
	array1D<int> b = NumCpp<int>::array({4, 5, 6});
	array1D<int> c = NumCpp<int>::array({7, 8, 9});
	array1D<int> d = NumCpp<int>::array({10, 11, 12, 13});
	array1D<int> e = NumCpp<int>::array({20, 30, 40, 50, 60, 70, 80, 90, 100});
	
	
	auto result = NumCpp<int>::concatenate(a, b, c, d, e);
	result.reshape(2, 3).print();
	
	
	return 0;
}