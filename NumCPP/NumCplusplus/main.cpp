
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;

int main(void){
	auto x = NumCpp<int>::array({1, 2, 3 ,4 ,5 ,6});
	auto b = NumCpp<int>::array({{1, 2, 3},{2, 4, 5}});
	
	cout << _int::len(x) << endl;
	cout << _int::len(b) << endl;
}