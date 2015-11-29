#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <iostream>
#include <vector>


using namespace std;

namespace numcpp{
	template <class T> class array2D;
	template <class T> class array3D;
	
	template <class T> class array1D{
	public:
		//typedefs
		typedef vector <T> oneDimensionalArray;
		typedef vector < oneDimensionalArray > twoDimensionalArray;
		typedef vector < twoDimensionalArray > threeDimensionalArray;
		
		
		//Structure for storing sizeshape
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
		
	
		//ctor
		array1D(oneDimensionalArray &arr);
		array1D(twoDimensionalArray &arr);
		array1D(threeDimensionalArray &arr);
		array1D(void) {}
		//Copy Constructor
		
		//print
		void print(int dimension = 1);
		
		//reshaper
		array1D<T> reshape(size_t r);
		array2D<T> reshape(size_t r, size_t c);
		array3D<T> reshape(size_t r, size_t c, size_t h);
		
		
		
		
		//Returns shape structure
		sizeShape shape(void) const;
		
		//Returns row/column
		size_t getRow(void) const;
		size_t getColumn(void) const;
		size_t getHeight(void) const;
		
		//returns length
		size_t len(void) const;
		
		//Operator = overloading for copying object
		array1D &operator = (array1D &other){
			var1D = other.var1D;
			var2D = other.var2D;
			var3D = other.var3D;
			_shape = other._shape;
			return *this;
		}
		
		//returns corresponding indexed value [without bound checking]
		T& operator[](size_t index);
		
		//Clears the array
		void clear(void);
		
		~array1D(void){
			
		}
		
		
		void fill(T t);
		
	private:
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		threeDimensionalArray var3D;
		sizeShape _shape;
		
	};
	
	template <class T> array1D<T>::array1D(oneDimensionalArray &arr){
		var1D = arr;
		_shape.row = 1;
		_shape.column = var1D.size();
		_shape.height = 0;
	}
	
	template <class T> array1D<T>::array1D(twoDimensionalArray &arr){
		var2D = arr;
		_shape.row = var2D.size();
		_shape.column = var2D[0].size();
		_shape.height = 0;
	}
	
	template <class T> array1D<T>::array1D(threeDimensionalArray &arr){
		var3D = arr;
		_shape.row = var3D.size();
		_shape.column = var3D[0].size();
		_shape.height = var3D[0][0].size();
	}
	
	//Printing Definition
	template <class T> void array1D<T>::print(int dimension){
		switch(dimension){
			case 1:
				for (size_t i = 0; i < var1D.size(); i++){
					cout << var1D[i] << " ";
				}
				cout << endl;
				break;
			case 2:
				for (size_t i = 0; i < var2D.size(); i++){
					for (size_t j = 0; j < var2D[i].size(); j++){
						cout << var2D[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				break;
			default:
				cout << "Argument not recognized, try 1 or 2" << endl;
				break;
		}
	}
	
	//Reshaping subroutines [1D]
	template <class T> array1D<T> array1D<T>::reshape(size_t r){
		oneDimensionalArray t;
		for (size_t i = 0; i < r; i++){
			t.push_back(var1D[i]);
		}
		array1D<T> temp(t);
		return temp;
	}
	
	//Reshaping Subroutine [2D]
	template <class T> array2D<T> array1D<T>::reshape(size_t r, size_t c){
		typename oneDimensionalArray::iterator it = var1D.begin();
		twoDimensionalArray t(r, oneDimensionalArray (c));
		for (size_t i = 0; i < r; i++){
			for (size_t j = 0; j < c; j++){
				if (it == var1D.end()){
					array1D::var2D = t;
					array2D<T> temp(t);
					return temp;
				}
				(t[i])[j] = *it;
				it++;
			}
		}
		array1D::var2D = t;
		array2D<T> temp(t);
		return temp;
	}
	
	//Reshaping Subroutine [3D] (Later)
	
	
	//Size returning function
	template <class T> typename array1D<T>::sizeShape array1D<T>::shape(void) const {
		return _shape;
	}
	
	//Returns length
	template <class T> size_t array1D<T>::len(void) const{
		return var1D.size();
	}
	
	//subscript operator overloading
	template <class T> T& array1D<T>::operator [](size_t index){
		//Error checking [LATER]
		return var1D[index];
	}
	
	template <class T> size_t array1D<T>::getColumn(void) const {
		return shape().column;
	}
	
	template <class T> size_t array1D<T>::getRow(void) const {
		return shape().row;
	}
	
	template <class T> size_t array1D<T>::getHeight(void) const {
		return shape().height;
	}
	
	
	//Fills the array with one type of element
	template <class T> void array1D<T>::fill(T t){
		for (size_t i = 0; i < var1D.size(); i++){
			var1D[i] = t;
		}
	}

}

#endif