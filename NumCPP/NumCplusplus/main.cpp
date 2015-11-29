
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;

int main(void){
	
	array2D<int> balsal = NumCpp<int>::array({ {1, 2, 3}, {2, 4 ,5}});
	
	balsal.transpose();
	
	balsal.print();
	
	
	
	
	return 0;
}