#include <iostream>
#include <fstream>
#include "factory/figure.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    // Not scaleable factory:
    // Not scaleable factory:
    std::ofstream factoryFile("factory.txt");
    Figure *square = createObj(Figure::Type::SQUARE);
    Figure *circle = createObj(Figure::Type::CIRCLE);
    square->write(factoryFile);
    circle->write(factoryFile);
    factoryFile.close();

    std::ifstream factoryFileToRead("factory.txt");
    Figure *square2 = create(factoryFileToRead);
    Figure *circle2 = create(factoryFileToRead);

//    ifstream file ("factory.bin", ios::in|ios::binary|ios::ate);

    // Scaleable factory:
    return 0;
}
