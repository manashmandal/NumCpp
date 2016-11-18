#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include "NumCpp.hpp"

using namespace std;
using namespace numcpp;

typedef NumCpp<int> _int;

// <iostream> declares cout/cerr, but the application must define them
// because it's up to you what to do with them.
namespace std
{
  ohserialstream cout(Serial);
}

vector<string> strings;

void setup(void)
{
  Serial.begin(9600);
  cout << "They see me printing, they hatin'" << endl;
  
  auto x = _int::array({1, 2, 3, 4, 5, 6});
  auto y = _int::array({{1, 2, 3},
                        {4, 5, 6}});
                        

  auto arr2d = x.reshape(3, 2);

  cout << endl;
  
  arr2d.transpose().print();

  array1D<int> arr = NumCpp<int>::array(NumCpp<int>::range(10));
  arr.print();
  
}

void loop(void)
{

}

// vim:cin:ai:sts=2 sw=2 ft=cpp

