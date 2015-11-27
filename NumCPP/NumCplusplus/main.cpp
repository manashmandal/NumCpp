
#include <NumCpp.hpp>
#include <vector>

using namespace std;
using namespace numcpp;


int main(void){
	auto x = NumCpp<int>::array({1, 2, 3 ,4 ,5 ,6});
	x.reshape(4, 4);
	x.print(2);
	return 0;
}