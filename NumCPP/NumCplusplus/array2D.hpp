#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <vector>

using namespace std;

namespace numcpp{
	template <class T> class array2D{
	public:
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		
		array2D(twoDimensionalArray &arr);
		
	private:
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		
		
	};
	
	template <class T> array2D<T>::array2D(twoDimensionalArray &arr){
		var2D = arr;
	}
}

#endif