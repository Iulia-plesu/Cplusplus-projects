#include "DoctorManager.h"

DoctorManager::DoctorManager(const std::string& fileName)
	: fileName(fileName)
{
	loadFromFile();
}

void DoctorManager::loadFromFile()
{
	std::ifstream fin(fileName);
	if (!fin) {
		std::cerr << "Error opening file\n";
		return;
	}

	std::string line;
	while (std::getline(fin, line)) {

		std::string type, firstName, lastName, gender, speciality;
		Data* birthDate = new Data(0, 0, 0);

		size_t pos = line.find(',');
		type = line.substr(0, pos);
		line.erase(0, pos + 1);

		if (type == "Doctor") {
			pos = line.find(',');
			firstName = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(',');
			lastName = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(',');
			birthDate->day = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);
			pos = line.find(',');
			birthDate->month = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);
			pos = line.find(',');
			birthDate->year = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			pos = line.find(',');
			gender = line.substr(0, pos);
			line.erase(0, pos + 1);
			
			pos = line.find(',');
			speciality = line.substr(0, pos);
			line.erase(0, pos + 1);

			Doctor doctor(firstName, lastName, birthDate, gender, speciality);
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
	std::cout << "Doctors:\n";
	for (const auto& doctor : doctors) {
		doctor.displayInfo();
		std::cout << '\n';
	}
}
