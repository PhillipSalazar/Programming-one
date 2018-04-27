#include <iostream>
using namespace std;

int main(){

int num = 0;
int savenum = 0;
int rightmostdigit = 0;
int number[6] = {0}; 
int w_factor[6] = {7,8,9,0,1,2,};
int sum[6] = {0};
char letter[10] = {'a','b','c','d','e','f','g','h','i'};
int total = 0;
int c = 5;
int i = 0;
int checkdigit = 0;
char lettercheckdigit = 'b';

cout << "\nPlease enter 6 digit acount: ";
cin >> num;

while (savenum > 0){
    rightmostdigit = savenum % 10;
    savenum = savenum % 10;
    number[c] = rightmostdigit;
    c--;
} 

for (i = 0; i < 6; i++){
    cout << "\ni = " << i << number[i];
    sum[i] = number[i] * w_factor[i];
    total = total + sum[i];
} 

checkdigit = total % 10;
lettercheckdigit = letter[checkdigit];

cout << "\nThe check digit was: " << checkdigit << endl;
cout << "\nThe letter check digit was: " << lettercheckdigit;
cout << "\nThe account was: ";
for (i = 0; i < 6; i++){
    cout << number[i];

}

cout << endl;

return 0;
}