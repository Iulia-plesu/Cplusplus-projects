#include "PatientManager.h"

PatientManager::PatientManager(const std::string& fileName)
	: fileName(fileName)
{
	loadFromFile();
}

void PatientManager::loadFromFile()
{
	std::ifstream fin(fileName);
	if (!fin) {
		std::cerr << "Error opening file\n";
		return;
	}
	patients.clear();

	std::string line;
	while (std::getline(fin, line)) {
		
		std::string type, firstName, lastName, gender, medicalHistory, token, illness, doctor, date;
		Data* birthDate;
		size_t pos = line.find(',');
		type = line.substr(0, pos);
		line.erase(0, pos + 1);

		if (type == "Patient") {
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
			medicalHistory = line.substr(0, pos);
			line.erase(0, pos + 1);

			Patient patient(firstName, lastName, birthDate, gender, medicalHistory);

			while (!line.empty()) {
				pos = line.find(';');
				illness = line.substr(0, pos);
				line.erase(0, pos + 1);
				patient.set_familyMedicalHistory(illness);
			}

			/*while (std::getline(fin, line, ';')) {
				pos = line.find(':');
				firstName = line.substr(0, pos);
				line.erase(0, pos + 1);
				date = line;

				pos = line.find(':');
				lastName = line.substr(0, pos);
				line.erase(0, pos + 1);
				date = line;

				patient.set_appointment(firstName, lastName, date);
			}*/

			
			patients.push_back(patient);
		}
	}
}

void PatientManager::saveToFile() const
{
	std::ofstream fout(fileName);
	if (!fout) {
		std::cerr << "Error opening file.\n";
		return;
	}
	for (const auto& patient : patients) {
		fout << "Name: " << patient.get_name() << '\n';
		fout << "Age: " << patient.get_age() << '\n';
		fout << "Gender: " << patient.get_gender() << '\n';
		fout << "Medical history: " << patient.get_medicalHistory() << '\n';
		fout << "Family medical history: ";
		for (const auto& illness : patient.get_familyMedicalHistory()) {
			fout << illness << ", ";
		}
		fout << "\nAppointments:\n";
		for (const auto& appointment : patient.get_appointments()) {
			fout << "Doctor: " << appointment.first << ", Date: " << appointment.second << '\n';
		}
	}
	fout.close();
}

void PatientManager::set_newPatient(const Patient& patient)
{
	patients.push_back(patient);
	saveToFile();
}

void PatientManager::displayPatients()
{
	std::cout << "Patients:\n";
	for (const auto& patient : patients) {
		patient.displayInfo();
		std::cout << "\n";
	}
}
