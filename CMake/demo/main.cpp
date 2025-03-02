#include <iostream>
#include "config.h"
#include "addition.h"
#include "subtract.h"
#include "multiply.h"
#include "divition.h"



using namespace std;



int main() {
    cout<<"version: "<<PROJECT_VERSION_MAJOR<<"."<<PROJECT_VERSION_MINOR<<endl;
#ifdef DATE
    cout<<"date: "<<DATE<<endl;
#endif
    cout<<"1+2= "<<add(1,2)<<endl;
    cout<<"2-1= "<<sub(2,1)<<endl;
//    cout<<"2*3= "<<mult(2,3)<<endl;
//    cout<<"6/2= "<<divi(6,2)<<endl;
    return 0;
}
