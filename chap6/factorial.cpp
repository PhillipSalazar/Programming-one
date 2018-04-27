#include <iostream>
using namespace std;
long FACT(long n);
int main(){

int numIn = 0;
cout << "\nPlease enter an integer";
cin >>  numIn;

cout << "factorial of " << numIn << " is " << FACT(numIn) << endl;
 
return 0;
}

long FACT(long num){
    if (num == 0){
        return 1;
    } else {
        return(num * FACT(num -1));
    }
}