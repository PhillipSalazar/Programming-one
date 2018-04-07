
// grabing the i/o library for i/o operations
#include <iostream>

// the prototyping is done in the header file name prototype.h. 
#include "prototype.h"

// all of our code is in the functions.cpp file for a more cleaner look.
#include "functions.cpp"

using namespace std;

// main functions
int main(){
    // a dummy value just in case it is run on Visual studios.
    int dum;


    // initalize the object functions where we are going to 
    // do all of our code in the object for a more presentable manner.
    Functions function;


        //function.vehicle;
    function.vehicle;
    function.hoursIn;
    function.minutesIn;
    function.hoursOut;
    function.minutesOut;


    /* 
        Initialize the functions that
        the program is going to use.
    */ 
    function.getUser(&vehicle, &hoursIn, &minutesIn, &hoursOut, &minutesOut);
    function.getUser();
    function.getTime();
    function.getRate();
    function.getCharge();
    function.printInfo();

    
    // console in dummy value for visual studios.
    cin >> dum;
    return 0;
} // end of main function .