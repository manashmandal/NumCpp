
#include <NumCpp.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	
	array2D<int> arr = NumCpp<int>::array({{1, 2, 3}, {3, 4, 5}});
	
	array1D<double> a = NumCpp<double>::array( {1.1 , 2.2 , 3.3} );
	a.print();
	
	
	
	auto bal = arr * arr;
	bal.print();
	
	return 0;
}