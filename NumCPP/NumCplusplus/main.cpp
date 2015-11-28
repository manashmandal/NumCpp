
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;

int main(void){
	array1D<int> balsal = NumCpp<int>::array({1, 2, 3});
	array1D<int> abal;
	abal = balsal;
	
	for (size_t i = 0; i < abal.getColumn(); i++){
		cout << abal[i] << endl;
	}
}