#include <iostream>
#include "config.h"
#include "addition.h"
#include "subtract.h"
using namespace std;


int main() {
    cout << "Hello, World!" << endl;
    cout << "version: " << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << endl;
#ifdef DATE
    cout << "date: " << DATE << endl;
#endif
    cout << "1+2= " << add(1,2) <<endl;
    cout << "1+2+3= " << add3(1,2,3) <<endl;
    cout << "2-1= " << sub(2,1) <<endl;

    return 0;
}
