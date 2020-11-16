#include <iostream>
#include <cmath>
#include "creditCard.h"
#include <string>
#include <sstream>



checkCreditCard::checkCreditCard() { // creates the constructor to ask for the creditCard
	
	std::cout << "Please enter a 16 digit credit card number that needs to be checked" << std::endl;

}


bool checkCreditCard::containsAllNumbers(long long int creditCardNumber) { // checks to see if the credit card is a number first
	bool isnum = true;
	std::stringstream ss;// create a string stream to convert the array into a string
	ss << creditCardNumber;
	std::string creditNumber = ss.str();

	for (int i = 0; i < creditNumber.length(); i++) { // iterates through the whole string

		if (!isdigit(creditNumber[i])) { // checks to see if it is not a digit
			isnum = false;
		}
	}

	return isnum;
}


bool checkCreditCard::validCreditCard(long long int& creditCardNumber) { // this validates the credit card with Luhns algorithm
	
	if (!containsAllNumbers(creditCardNumber)) { // first checks to see if it contains all numbers
		std::cout << "\nThe number you have entered contain a letter " << std::endl;
		return false;
	}

	creditCard.amountOfNumbers = (log10(creditCardNumber)) + 1; // this will get the amount of digits in the number they have entered
	int tempVar = 0; // a temp variable to help create the first set of numbers
	int tempVar2 = 0; // a temp variable to help create the second set of numbers
	int sum = 0; // the sum of the numbers after applying the algoirthm
	

	creditCard.arr = new int[creditCard.amountOfNumbers]; // this redeclares the array, with the amount of digits they have entered

	for (int i = creditCard.amountOfNumbers - 1; i >= 0 ; i--) { // this iterates the amount of digits they entered in the creditcard number

		creditCard.arr[i] = creditCardNumber % 10; // this will fill the array starting from the right, with the right most digit 
		creditCardNumber = creditCardNumber / 10; // divide by 10 to shift the number left one digit (deletes the rightmost number)

	}

	

	for (int i = creditCard.amountOfNumbers - 1; i >= 0; i--) {

		if (i % 2 == 0) { // if the iteration is on a even number, it fills the first set of numbers with whatever the original array is at the index
			creditCard.firstSet[tempVar] = creditCard.arr[i];
			tempVar++; // this increments tempVar once, so the next time the program it enters the if statement, it fills the next index of the array
		}
		else { // if the index is not even, it must be odd, so then it fills the second set of numbers
			creditCard.secondSet[tempVar2] = creditCard.arr[i];
			tempVar2++;
		}
	}

	//reset the tempVar variables
	tempVar = 0; 
	tempVar2 = 0;

	//** update so it iterates through the amount of numbers in the first set, not half of the original set
	// so the program can accept any number
	for (int i = 0; i < 8; i++) { // iterates through the length of the first set 
		
		tempVar = creditCard.firstSet[i] * 2; // this applys Luhns algorithm
		if (tempVar >= 10) { // this enters when if doubling the number in the first set gets a result greater than or equal to 10
			tempVar2 = tempVar % 10; // stores the first number from right in tempVar2
			tempVar = creditCard.firstSet[i] * 2 / 10; // stores the first number in tempVar
			creditCard.firstSet[i] = tempVar2 + tempVar; // sets the index to tempVar2 + tempVar, Luhns algorithm
			continue; // needs to continue onto the next iteration
		}

		creditCard.firstSet[i] = tempVar; // if doubling the number does not result in a number greater than or equal to 10, just change it in the
		//first set

		//resets the tempVar variables
		tempVar = 0;  
		tempVar2 = 0;
	}

	// ** will update so there is two for loops that iterate through both the first and second set, for the amount that is in both the first and second set
	// and then gets two differnt sums, then add those sums together
	for (int i = 0; i < 8; i++) {
		sum += creditCard.firstSet[i] + creditCard.secondSet[i];
	}

	if (sum % 10 == 0) { // if the number  is divisble bby 10, the number is valid
		creditCard.isValid = true;
	}

	return creditCard.isValid;
}


checkCreditCard::~checkCreditCard() {
	//delete creditCard.arr;
	std::cout <<  "Thank you for using this program" << std::endl;
}
