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
}

#endif