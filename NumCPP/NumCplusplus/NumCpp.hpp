#ifndef NUMCPP_H
#define NUMCPP_H

//Important includes
#include <iostream>
#include <vector>
#include <array1D.hpp>
#include <array2D.hpp>
#include <array3D.hpp>

using namespace std;

namespace numcpp{
	template <class T> class NumCpp{
	public:
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		typedef vector < twoDimensionalArray > threeDimensionalArray;
		
		static array1D<T> array(oneDimensionalArray arr);
		static array2D<T> array(twoDimensionalArray arr);
		static array3D<T> array(threeDimensionalArray arr);
		
	};
	
	template <class T> array1D<T> NumCpp<T>::array(oneDimensionalArray arr){
		array1D<T> temp(arr);
		return temp;
	}
	
	template <class T> array2D<T> NumCpp<T>::array(twoDimensionalArray arr){
		array2D<T> temp(arr);
		return temp;
	}
	
	template <class T> array3D<T> NumCpp<T>::array(threeDimensionalArray arr){
		array3D<T> temp(arr);
		return temp;
	}
}


#endif