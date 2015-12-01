#ifndef NUMCPP_H
#define NUMCPP_H

//Important includes
#include <iostream>
#include <vector>
#include <ostream>
#include <array1D.hpp>
#include <array2D.hpp>
#include <array3D.hpp>
#include <stdarg.h>

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
		
		//UnWrapper Function
		static array1D<T>& concatenate(array1D<T> &arr){
			return arr;
		}
		
		//Concatenation Method with variable input arguments 
		template <class ... Args> static array1D<T> concatenate(array1D<T> &arr, Args& ... args){
			array1D<T> t = arr;
			return t + concatenate(args...);
		}
		
		//Returns a 2D array containing ones and zeroes
		static array2D<T> ones(size_t row, size_t col);
		static array2D<T> zeroes(size_t row, size_t col);
		
		//Returns a 1D array containing ones
		static array1D<T> ones(size_t col);
		static array1D<T> zeroes(size_t col);
		
		
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
	
	template <class T> array2D<T> NumCpp<T>::ones(size_t row, size_t col){
		twoDimensionalArray t(row, oneDimensionalArray(col));
		array2D<T> temp(t);
		for (size_t i = 0; i < row; i++){
			for (size_t j = 0; j < col; j++){
				temp[i][j] = (T) 1.00;
			}
		}
		return temp;
	}
	
	template <class T> array2D<T> NumCpp<T>::zeroes(size_t row, size_t col){
		twoDimensionalArray t (row, oneDimensionalArray(col));
		array2D<T> temp(t);
		for (size_t i = 0; i < row; i++){
			for (size_t j = 0 ; j < col ; j++){
				temp[i][j] = 0;
			}
		}
		return temp;
	}
	
	template <class T> array1D<T> NumCpp<T>::ones(size_t col){
		oneDimensionalArray t(col);
		array1D<T> temp(t);
		for (size_t i = 0; i < col ; i++){
			t[i] = (T) 1.00;
		}
		return temp;
	}
	
	template <class T> array1D<T> NumCpp<T>::zeroes(size_t col){
		oneDimensionalArray t(col);
		array1D<T> temp(t);
		for (size_t i = 0; i < col; i++){
			temp[i] = 0;
		}
		return temp;
	}
	
	
}


#endif