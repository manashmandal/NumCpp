#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <vector>

using namespace std;

namespace numcpp{
	template <class T> class array1D;
	template <class T> class array3D;
	
	template <class T> class array2D{
	public:
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		typedef vector < twoDimensionalArray > threeDimensionalArray;
		
		//ctors
		array2D(twoDimensionalArray &arr);
		array2D(oneDimensionalArray &arr);
		array2D(threeDimensionalArray &arr);
		
		array1D <T> reshape(int r){
			oneDimensionalArray t(r);
			array1D<T> temp(t);
			return temp;
		}
		
		array3D<T> reshape(int r, int c, int h){
			threeDimensionalArray t(r, twoDimensionalArray (c, oneDimensionalArray (h)));
			array3D<T> temp(t);
			return temp;
		}
		
	private:
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		threeDimensionalArray var3D;
		
	};
	
	template <class T> array2D<T>::array2D(twoDimensionalArray &arr){
		var2D = arr;
	}
	
	template <class T> array2D<T>::array2D(oneDimensionalArray &arr){
		var1D = arr;
	}
	
	template <class T> array2D<T>::array2D(threeDimensionalArray &arr){
		var3D = arr;
	}
}

#endif