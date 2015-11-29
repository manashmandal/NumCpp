#ifndef NUMCPP_H
#define NUMCPP_H

//Important includes
#include <iostream>
#include <vector>
#include <ostream>
#include <array1D.hpp>
#include <array2D.hpp>
#include <array3D.hpp>

using namespace std;

namespace numcpp{
	template <class T> class array1D;
	template <class T> class array2D;
	template <class T> class array3D;
	
	template <class T> class NumCpp{
	public:
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		typedef vector < twoDimensionalArray > threeDimensionalArray;
		
		static array1D<T> array(oneDimensionalArray arr);
		static array2D<T> array(twoDimensionalArray arr);
		static array3D<T> array(threeDimensionalArray arr);
		
		static size_t len(array1D<T> &obj);
		static size_t len(array2D<T> &obj);
		
		//Returns a oneDimensionalArray creating a list of number given in the input
		static oneDimensionalArray range(int number);
		
		
		
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
	
	template <class T> size_t NumCpp<T>::len(array1D<T> &obj){
		return obj.len();
	}
	
	template <class T> size_t NumCpp<T>::len(array2D<T> &obj){
		return obj.len();
	}
	
	template <class T> typename NumCpp<T>::oneDimensionalArray NumCpp<T>::range(int number){
		oneDimensionalArray t;
		for (int i = 0; i < number; i++){
			t.push_back(i);
		}
		return t;
	}
	
}


#endif