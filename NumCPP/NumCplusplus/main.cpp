
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;


int main(void){

	typedef vector <double> one;
	typedef vector < one > two;
	
	two bal({{1, 2}, {2, 3}});
	array2D<double> abal(bal);
	

	


}