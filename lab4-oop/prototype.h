
/* Header File  */
/*
This is the header file to
the program that is suppose to calculate
parking fare is the parking lot.
*/

// prototype, defining variables.
#define fristCarRate 0.00
#define secondCarRate 1.50
#define firstTruckRate 1.00
#define secondTruckRate 2.30
#define firstBusRate 2.00
#define secondBusRate 3.70

// prototype functions
// Get user info function
void getUser(
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
    int *round
    );

void getRate(
    char vehicle,
    int *unit,
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