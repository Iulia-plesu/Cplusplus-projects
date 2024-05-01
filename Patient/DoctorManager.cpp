#include "DoctorManager.h"

DoctorManager::DoctorManager(const std::string& fileName)
	: fileName(fileName)
{}

void DoctorManager::readDoctors(std::istringstream& iss)
{
    std::string firstName, lastName, gender, speciality;
    int day, month, year;
    iss >> firstName >> lastName >> day >> month >> year >> gender >> speciality;

    Data birthDate(day, month, year);
    Doctor doctor(firstName, lastName, day, month, year, gender, speciality);
    this->set_newDoctor(doctor);
}

void DoctorManager::saveToFile() const
{
	std::ofstream fout(fileName);
	if (!fout) {
		std::cerr << "Error opening file\n";
		return;
	}
	for (const auto& doctor : doctors) {
		fout << "\nDoctor: " << doctor.get_name() << '\n';
		fout << "Age: " << doctor.get_age() << '\n';
		fout << "Gender: " << doctor.get_gender() << '\n';
		fout << "Speciality: " << doctor.get_speciality() << '\n';
	}
	fout.close();
}

void DoctorManager::set_newDoctor(const Doctor& doctor)
{
	doctors.push_back(doctor);
	saveToFile();
}
/*
void DoctorManager::displayDoctors() const
{
	std::cout << "\nDoctors:\n";
	for (const auto& doctor : doctors) {
		doctor.displayInfo();
		std::cout << '\n';
	}
}
*/