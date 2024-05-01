#include "DoctorManager.h"

DoctorManager::DoctorManager(const std::string& fileName)
	: fileName(fileName)
{
	loadFromFile();
}

void DoctorManager::loadFromFile() {
    std::ifstream fin(fileName);
    if (!fin) {
        std::cerr << "Error opening file\n";
        return;
    }

    doctors.clear();

    std::string line;
    while (std::getline(fin, line)) {
        std::string type, firstName, lastName, gender, speciality;
        int day, month, year;

        std::istringstream iss(line);
        if (std::getline(iss, type, ',') &&
            std::getline(iss, firstName, ',') &&
            std::getline(iss, lastName, ',') &&
            iss >> day >> std::ws &&
            iss >> month >> std::ws &&
            iss >> year >> std::ws &&
            std::getline(iss, gender, ',') &&
            std::getline(iss, speciality)) {

            
            Doctor doctor(firstName, lastName, day, month, year, gender, speciality);
            doctors.push_back(doctor);
        }
        
    }

    fin.close();
}


void DoctorManager::saveToFile() const
{
	std::ofstream fout(fileName);
	if (!fout) {
		std::cerr << "Error opening file\n";
		return;
	}
	for (const auto& doctor : doctors) {
		fout << "Doctor: " << doctor.get_name() << '\n';
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

void DoctorManager::displayDoctors() const
{
	std::cout << "\nDoctors:\n";
	for (const auto& doctor : doctors) {
		doctor.displayInfo();
		std::cout << '\n';
	}
}
