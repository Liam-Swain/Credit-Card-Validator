#pragma once
#include <iostream>


class checkCreditCard {
private:

	struct { // creates a struct to hold all the variables
		bool isValid = false;
		int* arr; // pointer to an array that we will declare later
		long long int amountOfNumbers; // this is for when I update the program to any amount of numbers
		int firstSet[8];
		int secondSet[8];

	}creditCard;
	 


public:

	checkCreditCard(); // the constructor just ask for the credit card number, and then calls validCreditCard 
	bool containsAllNumbers(long long int creditCardNumber); // first we need to check that the credit card number actually contains all numbers
	bool validCreditCard(long long int& creditCardNumber); // this will use the Luhns algorithm to check if the credit card is valid
	~checkCreditCard(); // destructor that deletes the creditCard array


};
