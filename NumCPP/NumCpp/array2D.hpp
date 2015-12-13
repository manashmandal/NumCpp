/*****
 * LEGEND:
 * [d] = [done]
 * [n] = [not done]
 * [p] = [partially done]
 * 
 * 
 * TODLIST:
 * -> Implementing Sample making subroutine [d]
 * -> Making a copy constructor [n]
 * -> Implement matrix operation [p]
 * 
 * */



#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <vector>

using namespace std;

namespace numcpp{
	template <class T> class array1D;
	template <class T> class array3D;
	template <class T> class NumCpp;
	
	template <class T> class array2D{
	public:
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		typedef vector < twoDimensionalArray > threeDimensionalArray;
		
		//ctors
		array2D(twoDimensionalArray &arr);
		array2D(oneDimensionalArray &arr);
		array2D(threeDimensionalArray &arr);
		array2D(void);

		
		twoDimensionalArray getArray2D(void){
			return var2D;
		}
		
		//Printing subroutine
		void print(short dimension = 2);
		
		//SizeShape
		struct sizeShape {
		public:
			size_t row;
			size_t column;
			size_t height;
			
			//Overloaded operator for sizeShape
			friend std::ostream& operator<<(std::ostream& os, sizeShape &s){
				os << "Row: " << s.row << endl
			   << "Column: " << s.column << endl
			   << "Height: " << s.height << endl;
				return os;
			}
		};
		
		sizeShape shape(void) const;
		
		//Returns length
		size_t len(void) const;
		
		//Fills the array with a specific element
		void fill(T t);
		
		
		//Returns array2D class
		array2D<T> transpose(void);
		array2D<T> transpose(bool isComposite);
		
		//gets column and rows
		size_t getColumn(void) const;
		size_t getRow(void) const;
		
		//Overloading double subscripting operator for matrix
		oneDimensionalArray& operator[](size_t index);
		
		
		//Array multiplication [Element wise, not MATRIX Multiplication]
		array2D<T> operator*(array2D<T> &other);
		
		//Matrix addition [Element wise]
		array2D<T> operator+(array2D<T> &other);
		
		//Matrix subtraction [Element wise]
		array2D<T> operator-(array2D<T> &other);
		
		//Matrix division [Element wise]
		array2D<T> operator/(array2D<T> &other);
		
		//Matrix modulo [Element wise]
		array2D<T> operator%(array2D<T> &other);
		
		//Makes a sample from input data
		static array2D<T> makeSample(array1D<T> &arr){
			tempArr.var2D.push_back(arr.getArray1D());
			return tempArr;
		}
		
		
		template <class...Args> array2D<T> static makeSample(array1D<T> arr, Args...args){
			auto x = makeSample(args...);
			x.var2D.push_back(arr.getArray1D());
			return x;
		}
		
		//Clears the static array 
		static void clear(void){
			tempArr.var2D.clear();
		}

		//Update the size
		void updateSize(void);

	private:
		static array2D<T> tempArr;
	
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		threeDimensionalArray var3D;
		
		
		sizeShape _shape;
		//Static array for holding static data

		
	};
	
	//Instanteniating the 2D array
	template <class T> array2D<T> array2D<T>::tempArr;
	
	//Ctors

	template <class T> array2D<T>::array2D(void) {}
	
	template <class T> array2D<T>::array2D(twoDimensionalArray &arr){
		var2D = arr;
		_shape.row = var2D.size();
		_shape.column = var2D[0].size();
		_shape.height = 0;
	}
	
	template <class T> array2D<T>::array2D(oneDimensionalArray &arr){
		var1D = arr;
		_shape.row = 1;
		_shape.column = var1D.size();
		_shape.height = 0;
	}
	
	template <class T> array2D<T>::array2D(threeDimensionalArray &arr){
		var3D = arr;
		_shape.row = var3D.size();
		_shape.column = var3D[0].size();
		_shape.height = var3D[0][0].size();
	}
	
	template <class T> void array2D<T>::print(short dimension){
		switch(dimension){
			case 2:
				for (size_t i = 0; i < var2D.size(); i++){
					for (size_t j = 0; j < var2D[i].size(); j++){
						cout << var2D[i][j] << " ";
					}
					cout << endl;
				}
				break;
			case 1:
				for (size_t i = 0; i < var1D.size(); i++){
					cout << var1D[i] << " ";
				}
				cout << endl;
				break;
			default:
				cout << "Dimensions only can be 1, 2 and 3" << endl;
				break;
		}
	}
	
	template <class T> typename array2D<T>::sizeShape array2D<T>::shape(void) const {
		return _shape;
	}
	
	//Returns length
	template <class T> size_t array2D<T>::len(void) const{
		return var2D.size();
	}
	
	//Fills up the array with a specific element
	template <class T> void array2D<T>::fill(T t){
		for (size_t i = 0; i < var2D.size(); i++){
			for (size_t j = 0; j < var2D[i].size(); j++){
				var2D[i][j] = t;
			}
		}
	}
	
	//Return row and column
	template <class T> size_t array2D<T>::getColumn(void) const {
		return _shape.column;
	}
	
	template <class T> size_t array2D<T>::getRow(void) const {
		return _shape.row;
	}
	
	//Transposes the matrix, operates on the composite class
		template <class T> array2D<T> array2D<T>::transpose(bool isComposite){
		size_t row = (*this).getArray2D()[0].size();
		size_t col = (*this).getArray2D().size();
		
		twoDimensionalArray tempMatrix(row, oneDimensionalArray(col));
		
		for (size_t i = 0; i < row; i++){
			for (size_t j = 0; j < col; j++){
				tempMatrix[i][j] = var2D[j][i];
			}
		}
		
		array2D<T> temp(tempMatrix);
		return temp;	
	}
	
	
	//Transposes the matrix, returns a temp class
	template <class T> array2D<T> array2D<T>::transpose(void){
		size_t col = _shape.row;
		size_t row = _shape.column;
		
		twoDimensionalArray tempMatrix(row, oneDimensionalArray(col));
		
		for (size_t i = 0; i < row; i++){
			for (size_t j = 0; j < col; j++){
				tempMatrix[i][j] = var2D[j][i];
			}
		}
		
		array2D<T> temp(tempMatrix);
		return temp;	
	}
	
	//Returns an element of given index [overloaded subscript operator]
	template <class T> typename array2D<T>::oneDimensionalArray& array2D<T>::operator[](size_t index){
		return var2D[index];
	}
	
	//Returns a 2D array of multiplied elements 
	template <class T> array2D<T> array2D<T>::operator*(array2D<T> &other){
		twoDimensionalArray t(other.getRow(), oneDimensionalArray(other.getColumn()));
		array2D<T> temp(t);
		for (size_t i = 0; i < other.getRow(); i++){
			for (size_t j = 0; j < other.getColumn(); j++){
				temp[i][j] = (*this)[i][j] * other[i][j];
			}
		}
		return temp;
	}
	
	//Adds two matrix [2D array]
	template <class T> array2D<T> array2D<T>::operator+(array2D<T> &other){
		twoDimensionalArray t(this->getRow(), oneDimensionalArray (this->getColumn()));
		for (size_t i = 0; i < this->getRow(); i++){
			for (size_t j = 0; j < this->getColumn(); j++){
				t[i][j] = (*this)[i][j] + other[i][j];
			}
		}
		array2D<T> temp(t);
		return temp;
	}
	
	//Subtracts two matrix
	template <class T> array2D<T> array2D<T>::operator-(array2D<T> &other){
		twoDimensionalArray t(this->getRow(), oneDimensionalArray (this->getColumn()));
		for (size_t i = 0; i < this->getRow(); i++){
			for (size_t j = 0; j < this->getColumn(); j++){
				t[i][j] = (*this)[i][j] - other[i][j];
			}
		}
		array2D<T> temp(t);
		return temp;
	}
	
	//Division between two matrix
	template <class T> array2D<T> array2D<T>::operator/(array2D<T> &other){
		twoDimensionalArray t(this->getRow(), oneDimensionalArray (this->getColumn()));
		for (size_t i = 0; i < this->getRow(); i++){
			for (size_t j = 0; j < this->getColumn(); j++){
				t[i][j] = (*this)[i][j] / other[i][j];
			}
		}
		array2D<T> temp(t);
		return temp;
	}

	//Modulo between two matrix
	template <class T> array2D<T> array2D<T>::operator%(array2D<T> &other) {
		twoDimensionalArray t(this->getRow(), oneDimensionalArray(this->getColumn()));
		for (size_t i = 0; i < this->getRow(); i++) {
			for (size_t j = 0; j < this->getColumn(); j++) {
				t[i][j] = (*this)[i][j] % other[i][j];
			}
		}
		array2D<T> temp(t);
		return temp;
	}
	
	template <class T> void array2D<T>::updateSize(void) {
		_shape.column = var2D.size();
		_shape.row = var2D[0].size();
	}

}

#endif