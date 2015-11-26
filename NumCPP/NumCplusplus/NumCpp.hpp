#ifndef NUMCPP_H
#define NUMCPP_H

#include <NumCpp_Includes.hpp>
#include <array1D.hpp>
#include <array2D.hpp>

using std::cout;
using std::vector;
using std::endl;

namespace numcpp
{
	template <class T> class NumCpp{
	public:
		static array1D<T> array(vector <T> initList){
			array1D<T> temp(initList);
			return temp;
		}
	};
}

#endif