
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;

int main(void){
	
	array2D<int> balsal = NumCpp<int>::array({ {1, 1, 1, 1, 1}, {2, 2,2, 2, 2}, {3, 3, 3, 3, 3}});
	
	auto dhon = NumCpp<int>::array(NumCpp<int>::range(10)).reshape(5, 2);
	
	dhon.print();
	
	dhon.transpose().print();
	
	
	
	return 0;
}