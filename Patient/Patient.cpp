#include "Patient.h"

Patient::Patient(const std::string& firstName, const std::string& lastName, int day, int month, int year, const std::string& gender, const std::string& medicalHistory)
	: Person(firstName, lastName, Data(day, month, year), gender)
	, medicalHistory(medicalHistory)
{}

Patient::~Patient()
{}

void Patient::displayInfo() const
{
	std::cout << "Name: " << firstName << " " << lastName << '\n';
	std::cout << "Age: " << get_age() << '\n';
	std::cout << "Gender: " << gender << '\n';
	std::cout << "Medical history: " << medicalHistory << '\n';
	std::cout << "Family medical history: ";
	for (const auto& illness : familyMedicalHistory) {
		std::cout << illness << " ";
	}
	std::cout << "\nAppointments:\n";
	for (const auto& appointment : appointments) {
		std::cout << "Doctor: " << appointment.first << ", Date: " << appointment.second << '\n';
	}
}

std::string Patient::get_medicalHistory() const
{
	return medicalHistory;
}

std::vector<std::string> Patient::get_familyMedicalHistory() const
{
	return familyMedicalHistory;
}

std::map<std::string, Data> Patient::get_appointments() const
{
	return appointments;
}

void Patient::set_familyMedicalHistory(const std::string& illness)
{
	familyMedicalHistory.push_back(illness);
}

void Patient::set_appointment(const std::string& firstName, const std::string& lastName, const Data& date)
{
	appointments[firstName + " " + lastName] = date;
}
