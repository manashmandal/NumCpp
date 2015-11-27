
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;


int main(void){
	auto x = NumCpp<int>::array({1, 2, 3 ,4 ,5 ,6});
	array1D<int>::sizeShape _s = x.shape();
	cout << _s << endl;
	
}