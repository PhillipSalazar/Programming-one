// Travis kind lab 04 
// Parking garage charges.
// create a program that will calculate a bill for parking in a garage.

#include <iostream>
#include <stdio.h>
using namespace std;

	//getInfo Function Prototype.
	void getInfo(char *vehicle, int *hourIn, int *minIn, int *hourOut, int *minOut);

	//time function prototype.
	void time(int hourIn, int minIn, int hourOut, int minOut, int *houtParkTime, int * minParkTime, int *roundedTotal, int *round);

	//rate function prototype.
	void rate(char vehicle, int *units, float *firstRate, float *secondRate);

	//charge function prototype.
	void charge(int roundedTotal, int units, float firstRate, float secondRate, float *totalCharge);

	//print function prototype.
	void print(char vehicle, int hourIn, int minIn, int hourOut, int minOut, int hourParkTime, int minParkTime, int roundedTotal, float totalCharge);

int main()
{

	#define firstCarRate 0.00 //first rate for cars.
	#define secondCarRate 1.25 //second rate for cars.
	#define firstTruckRate 3.75	//first rate for trucks.
	#define secondTruckRate 4.50 //second rate for trucks.
	#define firstBusRate 2.00 //first rate for buses.
	#define secondBusRate 2.50 //second rate for buses.


	//global variables
	char vehicle;
	int units;
	int hourIn;
	int minIn;
	int hourOut;
	int minOut;
	int hourParkTime;
	int minParkTime;
	int roundedTotal;
	int rounded;
	float firstRate;
	float secondRate;
	float totalCharge;

	//int main();

	  getInfo(&vehicle, &hourIn, &minIn, &hourOut, &minOut);
	  time(hourIn, minIn, hourOut, minOut, &hourParkTime, &minParkTime, &roundedTotal, &rounded);
	  rate(vehicle, &units, &firstRate, &secondRate);
	  charge(roundedTotal, units, firstRate, secondRate, &totalCharge);
	  print(vehicle, hourIn, minIn, hourOut, minOut, hourParkTime, minParkTime, roundedTotal, totalCharge);
	  
	  return 0;
  }

 

//function definition for get info.
	void getInfo(char *vehicle, int *hourIn, int *minIn, int *hourOut, int *minOut)
  {
	  cout << "\nType of vehicle? \n(enter C for car,T for truck, or B for bus): ";
	  cin >> *vehicle;

	  //check for valid vehicle type
	  /*{
		  switch (*vehicle)
		  {
		  case 'C': cout << "You entered C.\n";
		  case 'c': cout << "You entered c.\n";
			  break;
		  case 'T': cout << "You entered T.\n";
		  case 't': cout << "You entered t.\n";
			  break;
		  case 'B': cout << "You entered B.\n";
		  case 'b': cout << "You entered b.\n";
			  break;
		  default: cout << "You did not enter a valid vehicle type\n";
			  cout << "Please Enter C,c,T,t,B, or b\n";
			  return;
		  }
	  }*/
		  //get the hour that the vehicle entered the garage.
		  cout << "\nHour vehicle entered garage? ";
		  cin >> *hourIn;

		  //validate input for hourIn
		  if (*hourIn < 0 || *hourIn < 23)
		  {
			  cout << "invalid input. enter an integer between 0 and 23.";

		  }

		  //get the minute that the vehicle entered the garage.
		  cout << "\nMinute vehicle entered garage? ";
		  cin >> *minIn;
		  //validate input for minIn.
		  if (*minIn < 0 || *minIn > 60)
		  {
			  cout << "invalid input. enter a number between 0 and 60.";
		  }

		  //get the hour vehicle exits garage.
		  cout << "\nHour vehicle exits garage? ";
		  cin >> *hourOut;
		  //validate input for hourOut.
		  if (*hourOut < 0 || *hourOut < 23)
		  {
			  cout << "invalid input. enter an integer between 0 and 23.";
		  }

		  //get the minute vehicle exits garage.
		  cout << "\nMinute vehicle exits garage?";
		  cin >> *minOut;
		  //validate input for minOut.
		  if (*minOut < 0 || *minOut > 60)
		  {
			  cout << "invalid input. enter a number between 0 and 60.";

		  }
          return;
	  }
  


/*
  void getInfo(char *vehicle, int *hourIn, int *minIn, int *hourOut, int *minOut)
  {
  }
  */

  //function definition for time.
  void time(int hourIn, int minIn, int hourOut, int minOut, int *hourParkTime, int *minParkTime, int *roundedTotal, int *rounded)
		  {
			  if (minOut < minIn)
			  {
				  minOut = minOut + 60;
				  hourOut = hourOut - 1;
				  *hourParkTime = hourOut - hourIn;
				  *minParkTime = minOut - minIn;
			  }
			  else
			  {
				  *hourParkTime = hourOut - hourIn;
				  *minParkTime = minOut - minIn;
			  }
			  if (*minParkTime >= 1)
			  {
				  *rounded = *hourParkTime + 1;
				  *roundedTotal = *rounded;
			  }
			  else
			  {
				  *rounded = *hourParkTime;
				  *roundedTotal = *rounded;
			  }
			  return;
		  }

//Function definition for rate.

 void rate(char vehicle, int *units, float *firstRate, float *secondRate)
  {
  }
  
		  void rate(char *vehicle, int *units, float *firstRate, float *secondRate)
		  {


			  switch (*vehicle)
			  {
			  case 'c':
			  case 'C': *units = 3;
				  *firstRate = firstCarRate;
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
			  default: printf("\nPlease Enter a valid vehicle type.");
			  }
			  return;
		  }



//Function definition for charge.
		 // void charge(int roundedTotal, int units, float firstRate, float secondRate, float * totalCharge)
		
		  void charge(int roundedTotal, int units, float firstRate, float secondRate, float *totalCharge)
		  {
			  if (roundedTotal <= units)
			  {
				  *totalCharge = roundedTotal * firstRate;
			  }
			  else
			  {
				  *totalCharge = (roundedTotal - units) * (secondRate)+(units * firstRate);
			  }
			  return;
		  }
		
		 

		  //Function definition for print.
		  void print(char vehicle, int hourIn, int minIn, int hourOut, int minOut, int hourParkTime, int minParkTime, int roundedTotal, float totalCharge)
				  {
					  cout << " Vehicle Type:\t\t" << vehicle << endl;
					  cout << " Time In:\t\t" << hourIn << ":" << minIn << endl;
					  cout << " Time Out:\t\t" << hourOut << ":" << minOut << endl;
					  cout << " Total Park Time:\t" << roundedTotal << endl;
					  cout << " Total Charge:\t\t" << totalCharge << endl;
					  return;
				  }
