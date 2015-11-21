#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


namespace numcpp{

template <typename T> class oneDimensionalArray{
public:
    typedef vector <T> oneDimArray;
    typedef vector < oneDimArray > twoDimArray;
    typedef vector < twoDimArray > threeDimArray;

    oneDimArray vec1D;
    twoDimArray vec2D;
    threeDimArray vec3D;

    virtual void print(void) const {}
    virtual void print_2D(void) const{}
    virtual void print_3D(void) const{}
    virtual twoDimArray reshape(size_t, size_t)  {}

};

template <typename T> class array1D : public oneDimensionalArray<T>{
public:
    typedef vector <T> oneDimArray;
    typedef vector < oneDimArray > twoDimArray;
    typedef vector < twoDimArray > threeDimArray;

    oneDimArray vec1D;
    twoDimArray vec2D;
    threeDimArray vec3D;

    void print(void) const
    {
        for (size_t i = 0; i < vec1D.size(); i++){
            cout << vec1D[i] << " ";
        }
        cout << endl;
    }

    void print_2D(void) const {
        for (size_t i = 0; i < vec2D.size(); i++){
            for (size_t j = 0; j < vec2D[i].size(); j++){
                cout << vec2D[i][j] << " ";
            }
            cout << endl;
        }
    }

    array1D(oneDimArray v){
       vec1D = v;
    }

    //Reshapes 1D array into 2D and save it to 2D also returns a twoDimArray copy
    twoDimArray reshape(size_t r, size_t c){
        typename oneDimArray::iterator it = vec1D.begin();
        twoDimArray t_2D(r, vector<T>(c));

        for (size_t i = 0; i < r; i++){
            for (size_t j = 0; j < c; j++){
                if (it == vec1D.end()){
                    vec2D = t_2D;
                    return vec2D;
                }
                (t_2D[i])[j] = *it;
                it++;
            }
        }
        vec2D = t_2D;
        return vec2D;
    }

};

}

using namespace numcpp;

int main(void)
{
    numcpp::array1D<double> balsal({1.1, 2.2, 3.3, 5.5, 6.6, 7.7});
    balsal.reshape(6, 5);
    balsal.print_2D();

}
