#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <NumCpp.hpp>
#include <array1D.hpp>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class array1D;

namespace numcpp{
	template <class T> class array2D{
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		
	public:
		array2D(void){
			cout << "Hello array2d" << endl;
		}
	};	
}


#endif