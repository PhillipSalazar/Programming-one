#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
// prototype
void isPrime(int num);

// global file object
ofstream filez;

//main function
int main() {
    
    filez.open ("prime.txt");
    int num = 0;
    cout << "\nPlease enter upper limit: ";
    cin >> num;
    // is prime function
    isPrime(num);

    cout << "\nPrime number from 2 till " << num << " are in prime.txt";
    cout << endl;
    return 0;
} // end of main

// is prime function
void isPrime(int num){

for (int i=2; i< num; i++) 
    {
        bool prime=true;
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
            {
                prime=false;
                break;    
            }
        }   
        if(prime) filez << i << "\n";
    } 


    return;
} // end of isPrime