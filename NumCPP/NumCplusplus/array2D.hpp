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
		
		
	private:
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		threeDimensionalArray var3D;
		
		sizeShape _shape;
		
	};
	
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
}

#endif