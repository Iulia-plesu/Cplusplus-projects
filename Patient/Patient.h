#pragma once
#include "Person.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
class Patient : public Person
{
private:
	std::string medicalHistory;
	std::vector<std::string> familyMedicalHistory;
	std::map<std::string, Data> appointments;
public:
	Patient(const std::string& firstName, const std::string& lastName, int day, int month, int year, const std::string& gender, const std::string& medicalHistory);
	~Patient();

	void displayInfo() const override;

	std::string get_medicalHistory() const;
	std::vector<std::string> get_familyMedicalHistory() const;
	std::map<std::string, Data> get_appointments() const;

	void set_familyMedicalHistory(const std::string& illness);
	void set_appointment(const std::string& firstName, const std::string& lastName, const Data& date);

};

