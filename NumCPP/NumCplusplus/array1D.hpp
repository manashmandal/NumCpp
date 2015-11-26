#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <NumCpp_Includes.hpp>
#include <NumCpp.hpp>
#include <array2D.hpp>

template <class T> class array2D;

namespace numcpp
{
	template <class T> class array1D{
	
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		
	public:
		array1D (oneDimensionalArray &arr){
			array1d = arr;
		}
		
		oneDimensionalArray array1d; 
		
	};
}

#endif