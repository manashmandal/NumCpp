
#include <NumCpp.hpp>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;



int main(void){
	

	array2D<double> bal = NumCpp<double>::array({{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}});
	
	array2D<int> balsal = NumCpp<int>::array({{4, 16, 25}, {9, 36, 49}});
	
	array1D<int> dhon = _int::array({4, 9, 16, 36});
	array1D<double> double_dhon = NumCpp<double>::array({4.0, 25.0, 16.0});
	
	auto bal_chal = NumCpp<double>::_sqrt(double_dhon);
	
	auto balchal = NumCpp<double>::_sqrt(balsal);
	
	cout << "Balchal " << endl;
	balchal.print();
	
	NumCpp<double>::_sqrt(bal).print();
	
	
	
	
	return 0;
}