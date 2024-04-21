#include <iostream>
#include <string>
#include <ctime>


bool luhnAlgorithm(const std::string& card_number)
{
	int n_digits = card_number.length();

	int sum = 0, isSecond = false;
	for (int i = n_digits - 1; i >= 0; i--) {

		int d = card_number[i] - '0';

		if (isSecond == true)
		{
			d = d * 2;
		}
		sum += d / 10;
		sum += d % 10;

		isSecond = (isSecond ? false : true);
	}
	return (sum % 10 == 0);
}

bool nameValidation(const std::string& name) {
	if (name.empty())
		return false;
	int count = 0;
	for (char c : name) {
		if (!isalpha(c) && c != ' ') {
			return false;
		}
		count++;
	}

	if (count < 2)
		return false;
	return true;
}

bool expirationDateValidation(const std::string& expirationDate) {
	
	std::time_t currentTime = std::time(nullptr);
	std::tm now;
	localtime_s(&now, &currentTime); 

	int currentMonth = now.tm_mon + 1;
	int currentYear = now.tm_year + 1900;

	size_t delimiterPos = expirationDate.find('/');

	if (delimiterPos == std::string::npos) {
		std::cerr << "Invalid expiration date format.\n";
		return false;
	}
	std::string monthStr = expirationDate.substr(0, delimiterPos);
	std::string yearStr = expirationDate.substr(delimiterPos + 1);
	int expirationMonth, expirationYear;
	try {
		expirationMonth = std::stoi(monthStr);
		expirationYear = std::stoi(yearStr);
	}
	catch (const std::invalid_argument&) {
		std::cerr << "Invalid expiration date format.\n";
		return false;
	}
	catch (const std::out_of_range&) {
		std::cerr << "Invalid expiration date format.\n";
		return false;
	}

	if (expirationYear > currentYear || (expirationYear == currentYear && expirationMonth >= currentMonth))
		return true;
	return false;
}

bool codeValidation(const std::string& securityCode) {
	if (securityCode.length() != 3 && securityCode.length() != 4) {
		return false;
	}

	for (char c : securityCode) {
		if (!isdigit(c))
			return false;
	}

	return true;
}

void cardValidation() {
	std::string cardNumber, cardholderName, expirationDate, securityCode;

	std::cout << "Enter the card number: ";
	std::getline(std::cin, cardNumber);

	std::cout << "Enter the cardholder's name: ";
	std::getline(std::cin, cardholderName);

	std::cout << "Enter the expiration date (MM/YYYY): ";
	std::getline(std::cin, expirationDate);

	std::cout << "Enter the security code (CVV/CVC): ";
	std::getline(std::cin, securityCode);

	if (luhnAlgorithm(cardNumber) && nameValidation(cardholderName) &&
		expirationDateValidation(expirationDate) && codeValidation(securityCode)) 
		std::cout << "The card is valid.\n";
	else 
		std::cout << "The card is invalid.\n";
}


int main()
{
	cardValidation();
	return 0;
}
