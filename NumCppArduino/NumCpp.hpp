#ifndef NUMCPP_H
#define NUMCPP_H

//Important includes
#include <iostream>
#include <vector>
#include <ostream>
#include "array1D.hpp"
#include "array2D.hpp"
#include "array3D.hpp"
#include <stdarg.h>
#include <cmath>

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
		
		typedef vector <int> _intOneDimensionalArray;
		typedef vector < _intOneDimensionalArray > _intTwoDimensionalArray;
		typedef vector < _intTwoDimensionalArray > _intThreeDimensionalArray;
		
		typedef vector <double> _doubleOneDimensionalArray;
		typedef vector < _doubleOneDimensionalArray > _doubleTwoDimensionalArray;
		typedef vector < _doubleTwoDimensionalArray > _doubleThreeDimensionalArray;
		
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
		
		//Math function for pow [pow function applied on each element]
		static array1D<int> _pow (array1D<int> &t, int exp);
		static array1D<double> _pow(array1D<double> &t, double exp);
		static array2D<int> _pow(array2D<int> &t, int exp);
		static array2D<double> _pow(array2D<double> &t, double exp);
		
		//Math function for sqrt
		static array1D<double> _sqrt(array1D<int> &t);
		static array1D<double> _sqrt(array1D<double> &t);
		static array2D<double> _sqrt(array2D<int> &t);
		static array2D<double> _sqrt(array2D<double> &t);

		
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
	
	//Math functions [math.h -> pow(base, exp)]
	// pow for array1D<int>
	template <class T> array1D<int> NumCpp<T>::_pow(array1D<int> &t, int exp){
		vector <int> temp_arr(t.getColumn());
		for (size_t i = 0; i < t.getColumn(); i++){
			temp_arr[i] = pow(t[i], exp);
		}
		array1D<int> arr(temp_arr);
		return arr;
	}
	
	//pow for array1D<double>
	template <class T> array1D<double> NumCpp<T>::_pow(array1D<double> &t, double exp){
		vector <double> temp_arr(t.getColumn());
		for (size_t i = 0; i < t.getColumn(); i++){
			temp_arr[i] = pow(t[i], exp);
		}
		array1D<double> arr(temp_arr);
		return arr;
	}
	
	//Pow for array2D<int>
	template <class T> array2D<int> NumCpp<T>::_pow(array2D<int> &t, int exp){
		_intTwoDimensionalArray temp_arr (t.getRow(), _intOneDimensionalArray(t.getColumn()));
		for (size_t i = 0; i < t.getRow(); i++){
			for (size_t j = 0; j < t.getColumn(); j++){
				temp_arr[i][j] = pow(t[i][j], exp);
			}
		}
		array2D<int> arr(temp_arr);
		return arr;
	}
	
	//Pow for array2D<double>
	template <class T> array2D<double> NumCpp<T>::_pow(array2D<double> &t, double exp){
		_doubleTwoDimensionalArray temp_arr (t.getRow(), _doubleOneDimensionalArray(t.getColumn()));
		for (size_t i = 0; i < t.getRow(); i++){
			for (size_t j = 0; j < t.getColumn(); j++){
				temp_arr[i][j] = pow(t[i][j], exp);
			}
		}
		array2D<double> arr(temp_arr);
		return arr;
	}
	
	//Sqrt for array1D<int>
	template <class T> array1D<double> NumCpp<T>::_sqrt(array1D<int> &t){
		_doubleOneDimensionalArray double_arr(t.getColumn());
		for (size_t i = 0; i < t.getColumn(); i++){
			double place_holder = (double) t[i];
			double_arr[i] = pow(place_holder, 0.5);
		}
		array1D<double> temp(double_arr);
		return temp;
	}
	
	//Sqrt for array1D<double>
	template <class T> array1D<double> NumCpp<T>::_sqrt(array1D<double> &t){
		_doubleOneDimensionalArray temp_arr(t.getColumn());
		for (size_t i = 0; i < t.getColumn(); i++){
			temp_arr[i] = pow(t[i], 0.5);
		}
		array1D<double> temp(temp_arr);
		return temp;
	}
	
	//Sqrt for array2D<int>
	template <class T> array2D<double> NumCpp<T>::_sqrt(array2D<int> &t){
		_doubleTwoDimensionalArray temp_arr(t.getRow(), _doubleOneDimensionalArray ( t.getColumn()) );
		for (size_t i = 0; i < t.getRow(); i++){
			for (size_t j = 0; j < t.getColumn(); j++){
				double place_holder = (double) t[i][j];
				temp_arr[i][j] = pow(place_holder, 0.5);
			}
		}
		
		array2D<double> arr(temp_arr);
		return arr;
	}
	
	//Sqrt for array2D<double>
	template <class T> array2D<double> NumCpp<T>::_sqrt(array2D<double> &t){
		_doubleTwoDimensionalArray temp_arr(t.getRow(), _doubleOneDimensionalArray ( t.getColumn()) );
		for (size_t i = 0; i < t.getRow(); i++){
			for (size_t j = 0; j < t.getColumn(); j++){
				temp_arr[i][j] = pow(t[i][j], 0.5);
			}
		}
		array2D<double> arr(temp_arr);
		return arr;
	}

}


#endif