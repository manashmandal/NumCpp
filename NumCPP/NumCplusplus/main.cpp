
#include <NumCpp.hpp>


using namespace std;
using namespace numcpp;


int main(void){
	array1D<int> bal = NumCpp<int>::array({1, 2, 3});
	array2D<int> balsal = NumCpp<int>::array({{1, 2, 3}, {2, 3, 4}});
	array3D<int> balsalabal = NumCpp<int>::array({{{1, 2, 3}, {2, 3, 4}},{{1, 2, 3}, {2, 3, 4}}});
}