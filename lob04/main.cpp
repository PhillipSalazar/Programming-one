/*



*/
#include <stdio.h>
#include <iostream>
using namespace std;

// prototype, defining variables.
#define fristCarRate 0.00
#define secondCarRate 1.50
#define firstTruckRate 1.00
#define secondTruckRate 2.30
#define firstBusRate 2.00
#define secondBusRate 3.70

// prototype functions
// Get user info function
void getInfo(
    char *vehicle, 
    int *hourIn, 
    int *minIn, 
    int *hourOut, 
    int *minOut 
    );

// time function
void getTime(
    int hourIn,
    int hourOut,
    int minIn,
    int minOut,
    int *hourParkTime,
    int *minParkTime, 
    int *roundedTotal,
    int *rounded
    );

void getRate(
    char vehicle,
    int *units,
    float *fristRate,
    float *secondRate
    );

void getCharge(
    int roundedTotal,
    int unit,
    float firstRate,
    float secondRate,
    float *totalCharge
    );

void printInfo(
    char vehicle,
    int hourIn,
    int minIn,
    int hourOut,
    int minOut,
    int hourParkTime,
    int minParkTime,
    int roundedTotal,
    float totalCharge
    );
// end of prototype!!!



// imprting libraries 

//variables!!!!
// first set of variables is a character.
char vehicle;

// second set of variables are integers.
int hourIn;
int minIn;
int hourOut;
int minOut;
int hourParkTime;
int minParkTime;
int roundedTotal;
int rounded;
int units;

// third set of variables are floats.
float firstRate;
float secondRate;
float totalCharge;

// the Main function.
int main() {
    
    getInfo(&vehicle, &hourIn, &minIn, &hourOut, &minOut);
    getTime(hourIn,hourOut, minIn, minOut, &hourParkTime, &minParkTime, &roundedTotal, &rounded);
    getRate(vehicle, &units, &firstRate, &secondRate);
    getCharge(roundedTotal, units, firstRate, secondRate, &totalCharge);
    printInfo(vehicle, hourIn, minIn, hourOut, minOut, hourParkTime, minParkTime, roundedTotal, totalCharge);
    return 0;
}// end of main

// get info function.
/*
The getUser function, get the user's information for other calculations.
*/
void getInfo(char *vehicle, int *hourIn, int *minIn, int *hourOut, int *minOut) {
      // asking for type of vehicle
        /* only answer accepted is 
            'c' or 'C' for car,
            't' or 'T' for truck,
            'b' or 'B' for Bus.
        */
        //do {
        cout << "What is your vehicle type? ";
        cin >> *vehicle;
    /*    } while ((*vehicle == 'c') ||  
                 (*vehicle == !'C') ||
                 (*vehicle == !'t') ||
                 (*vehicle == !'T') ||
                 (*vehicle == !'b') ||
                 (*vehicle == !'B')  
                 );
                 */
        // asking for hours in.
        // answer must be only a real number
        
        cout << "Hours in: ";
        cin >> *hourIn;
        
        // asking for minutes in.
        // answer must be only a real number.      
        cout << "Minutes in: ";
        cin >> *minIn;
        
        // asking for hours out.
        // answer must be only a real number.
        cout << "Hours out: ";
        cin >> *hourOut;
        
        // asking for minutes out.
        // answer must be only a real number.
        cout << "Minutes out: ";
        cin >> *minOut;
        // validation
    
        return;
}// end of the getInfo function.

// get time function.
void getTime(int hourIn, int hourOut, int minIn, int minOut, int *hourParkTime, int *minParkTime, int *roundedTotal, int *rounded) {
        
    if (minOut < minIn){
        minOut = minOut + 60;
        hourOut = hourOut - 1;
        *hourParkTime = hourOut - hourIn;
        *minParkTime = minOut - minIn;
    } else {
        *hourParkTime = hourOut - hourIn;
        *minParkTime = minOut - minIn;
    }

    if (*minParkTime >= 1){
        *rounded = *hourParkTime + 1;
        *roundedTotal = *rounded;
    }else {
        *rounded = *hourParkTime;
        *roundedTotal = *rounded;
    }
    return;
}// end of the getTime function.

void getRate(char vehicle, int *units, float *firstRate, float *secondRate) {

    switch(vehicle){
        case 'c':
        case 'C': *units = 3;
        *firstRate = fristCarRate;
        *secondRate = secondCarRate;
        break;

        case 't':
        case 'T': *units = 2;
        *firstRate = firstTruckRate;
        *secondRate = secondTruckRate;
        break;

        case 'b':
        case 'B': *units = 1;
        *firstRate = firstBusRate;
        *secondRate = secondBusRate;
        break;
        default: printf("\n You did not enter a valid letter!");
        printf("\nGood day!!!");
    }// end of switch
    return;
}// end of the getRate function.

// get charge function
void getCharge(int roundedTotal, int units, float firstRate, float secondRate, float *totalCharge) {

    if (roundedTotal <= units){
        *totalCharge = roundedTotal * firstRate;
    } else {
        *totalCharge = (units * firstRate) + ((roundedTotal - units) * secondRate); 
    }
    return;
}// end of the getCharge function.

// the pritn function
void printInfo(char vehicle, int hourIn, int minIn, int hourOut, int minOut, int hourParkTime, int minParkTime, int roundedTotal, float totalCharge) {
    cout << endl << endl;


    cout << "Your vehicle is a: " << vehicle << endl;
    cout << "Hours in: " << hourIn << endl;
    cout << "Minutes in: " << minIn << endl;
    cout << "Hours out: " << hourOut << endl;
    cout << "Minutes out: " << minOut << endl;
    cout << "The amount of hours you parked: " << hourParkTime << endl;
    cout << "The amount of minutes you parked: " << minParkTime << endl;
    cout << "The rounded time you vehicle was here for: " << roundedTotal << endl;
    cout << "The amount due!!! " << totalCharge << endl;
    return;
}// end of the print function.