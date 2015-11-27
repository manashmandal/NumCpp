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
		
		//ctor
		array1D(oneDimensionalArray &arr);
		array1D(twoDimensionalArray &arr);
		array1D(threeDimensionalArray &arr);
		
		//print
		void print(int dimension = 1);
		
		array2D<T> reshape(int r, int c){
			twoDimensionalArray t(r, oneDimensionalArray(c));
			array2D<T> temp(t);
			return temp;
		}
		
		array1D<T> reshape(int r, int c, int h){
			threeDimensionalArray t(h, twoDimensionalArray (r, oneDimensionalArray (c)));
			array3D<T> temp(t);
			return temp;
		}
		
	private:
		oneDimensionalArray var1D;
		twoDimensionalArray var2D;
		threeDimensionalArray var3D;
		
	};
	
	template <class T> array1D<T>::array1D(oneDimensionalArray &arr){
		var1D = arr;
	}
	
	template <class T> array1D<T>::array1D(twoDimensionalArray &arr){
		var2D = arr;
	}
	
	template <class T> array1D<T>::array1D(threeDimensionalArray &arr){
		var3D = arr;
	}
	
	
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
}

#endif