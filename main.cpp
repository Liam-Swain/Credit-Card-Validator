
#include "creditCard.h"


int main() {
	long long int* creditCardNumber = new long long int; 
	std::cout << "Liam Swain, Simple Credit Card Checker November 10th 2020" << std::endl;
	checkCreditCard check;
	std::cin >> *creditCardNumber; // this gets the credit card they want to check

	if (check.validCreditCard(*creditCardNumber)) { // check if the number is valid
		std::cout << "\nThe number you entered is valid" << std::endl;
	}

	else {
		std::cout << "\nThe credit card you entered is not valid" << std::endl;
	}

	return 0;
}
