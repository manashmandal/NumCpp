
#include <NumCpp.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	
	array2D<double> x = NumCpp<double>::ones(2, 3);
	
	array2D<int> bal = NumCpp<int>::ones(5,4);
	
	bal.print();
	
	array2D<int> ze = NumCpp<int>::zeroes(2,3);
	
	ze.print();
	
	return 0;
}