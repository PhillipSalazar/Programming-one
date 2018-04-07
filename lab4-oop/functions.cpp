

#include <iostream>
using namespace std;

class Functions {
    public:
    


    /* the getUser fuction get the user
       information with so validation.
    */
    void getUser(    
    char *vehicle, 
    int *hourIn, 
    int *minIn, 
    int *hourOut, 
    int *minOut )
    {
        // asking for type of vehicle
        /* only answer accepted is 
            'c' or 'C' for car,
            't' or 'T' for truck,
            'b' or 'B' for Bus.
        */
        cout << "What is your vehicle type? ";
        cin >> vehicle;
        
        // asking for hours in.
        // answer must be only a real number.
        cout << "Hours in: ";
        cin >> hoursIn;

        // asking for minutes in.
        // answer must be only a real number.      
        cout << "Minutes in: ";
        cin >> minutesIn;
        
        // asking for hours out.
        // answer must be only a real number.
        cout << "Hours out: ";
        cin >> hoursOut;
        
        // asking for minutes out.
        // answer must be only a real number.
        cout << "Minutes out: ";
        cin >> minutesOut;
        // validation
        return;
    } //end of the getUser function.

    void getTime(
    int hourIn, 
    int hourOut, 
    int minIn, 
    int minOut, 
    int *hourParkTime, 
    int *minParkTime, 
    int *roundedTotal, 
    int *round
    ) 
    {


        return;
    }

    void getRate() {

        return;
    }

    void getCharge() {

        return;
    }

    void printInfo() {

        return;
    }

};

