#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include "Data.h"

class Person
{
protected:
	std::string firstName;
	std::string lastName;
	Data birthDate;
	std::string gender;

	
public:
	Person(const std::string& firstName, const std::string& lastName, Data birthDate, const std::string& gender);
	~Person();

	int calculateAge() const;

	std::string get_name() const;
	std::string get_gender() const;
	int get_age() const;
	virtual void displayInfo() const = 0;
};

