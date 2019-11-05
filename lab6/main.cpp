#include <iostream>
#include <string>
#include "set.hpp"
#include "Vector.hpp"

using namespace std;


int main()
{
    Vector<double> hell;
    double a = 12.2;

    hell.push(a);
    hell.push(2);
    hell.push(3);
    hell.push(4);

    for (int i = 0; i < hell.GetSize(); i++) {
      cout << hell[i] << endl;
    }


    return 0;
}
