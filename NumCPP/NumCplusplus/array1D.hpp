#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <iostream>
#include <vector>


using namespace std;

namespace numcpp{
	template <class T> class array1D{
	public:
		//typedefs
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		typedef vector < twoDimensionalArray > threeDimensionalArray;
		
		//ctor
		array1D(oneDimensionalArray &arr);
		
	private:
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		threeDimensionalArray var3D;
		
	};
	
	template <class T> array1D<T>::array1D(oneDimensionalArray &arr){
		var1D = arr;
	}
}

#endif