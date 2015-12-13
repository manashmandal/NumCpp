
#include <NumCpp.hpp>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	
	auto frontSonar = _int::array({1, 2, 3, 4});
	auto lSonar = _int::array({5, 6, 7, 8});
	auto balSonar = _int::array({9, 10, 11, 12});
	auto dhonSonar = _int::array({13, 14, 15, 16});
	
	
	array2D<int>::makeSample(frontSonar);
	
	array2D<int>::clear();
	
	auto dhon = array2D<int>::makeSample(dhonSonar, balSonar, lSonar, frontSonar);
	dhon.transpose(true).print();
	
	
	
	return 0;
}