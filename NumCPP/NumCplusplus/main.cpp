
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	
	array1D<int> bal = NumCpp<int>::array({1, 2, 3});
	array1D<int> sal = NumCpp<int>::array({4, 5, 6});
	array1D<int> abal = NumCpp<int>::array({7, 8, 9});
	
	auto dhon = bal + sal;
	auto khanki = dhon + abal;
	
	
	khanki.print();
	
	return 0;
}