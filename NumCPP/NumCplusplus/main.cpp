
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;


int main(void){
	auto x = NumCpp<int>::array({1, 2, 3 ,4 ,5 ,6});
	auto y = x.shape();
	cout << y.row << endl;
	cout << y.column << endl;
}