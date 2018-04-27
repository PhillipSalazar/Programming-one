#include <iostream>
#include <cmath>
using namespace std;

double futureValue(double present_value, double interest, int timez);

double future_value = 0;
double present_value = 0;
double interest = 0;
int timez = 0;


int main () {

   // inputz(&present_value, &interest, &timez);

cout << "\nPlease enter present value of the account: ";
cin >> present_value;
cout << "\nPlease enter interested rate: ";
cin >> interest;
cout << "\nPlease enter the amount time of time in month: ";
cin >> timez;

cout << "\n Your future value is: " << futureValue(present_value, interest, timez) << endl;

    return 0;
}
/*
void inputz( double present_value, double interest, int timez ) {


return;
}
*/
double futureValue(double present_value, double interest, int timez) {

double future_value = present_value * (pow(1 + interest, timez));

return future_value;

    
}