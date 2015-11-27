
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;


int main(void){
	auto x = NumCpp<int>::array({1, 2, 3 ,4 ,5 ,6});
	auto b = NumCpp<int>::array({{1, 2, 3},{2, 4, 5}});
	
	auto c = x.reshape(2, 3);
	
	c.print();
	auto size = c.shape();
	
	cout << size << endl;
	return 0;
}