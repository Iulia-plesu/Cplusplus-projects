#include "PatientManager.h"

PatientManager::PatientManager(const std::string& fileName)
	: fileName(fileName)
{
	loadFromFile();
}

void PatientManager::loadFromFile() {
    std::ifstream fin(fileName);
    if (!fin) {
        std::cerr << "Error opening file\n";
        return;
    }

    patients.clear();

    std::string line;
    while (std::getline(fin, line)) {
        std::string type, firstName, lastName, gender, medicalHistory, illness, doctor, date;
        int day, month, year;

        std::istringstream iss(line);
        std::getline(iss, type, ',');

        if (type == "Patient") {
            std::getline(iss, firstName, ',');
            std::getline(iss, lastName, ',');

            char delimiter;
            iss >> day >> delimiter >> month >> delimiter >> year;

            std::getline(iss, gender, ',');
            std::getline(iss, medicalHistory, ',');

            Patient patient(firstName, lastName, day, month, year, gender, medicalHistory);

            while (std::getline(iss, illness, ';')) {
                patient.set_familyMedicalHistory(illness);
            }

            while (std::getline(fin, line, ';')) {
                std::istringstream appointmentIss(line);
                std::getline(appointmentIss, firstName, ':');
                std::getline(appointmentIss, date, ':');
                std::getline(appointmentIss, lastName, ':');

                appointmentIss >> day >> delimiter >> month >> delimiter >> year;

                Data appointmentDate(day, month, year);

                patient.set_appointment(firstName, lastName, appointmentDate);
            }

            patients.push_back(patient);
        }
    }

    fin.close();
}


void PatientManager::saveToFile() const
{
	std::ofstream fout(fileName);
	if (!fout) {
		std::cerr << "Error opening file.\n";
		return;
	}
	for (const auto& patient : patients) {
		fout << "\nName: " << patient.get_name() << '\n';
		fout << "Age: " << patient.get_age() << '\n';
		fout << "Gender: " << patient.get_gender() << '\n';
		fout << "Medical history: " << patient.get_medicalHistory() << '\n';
		fout << "Family medical history: ";
        if (patient.get_familyMedicalHistory().empty()) {
            fout << "No family medical history available.\n";
        }
        else {
            for (const auto& illness : patient.get_familyMedicalHistory()) {
                fout << illness << " ";
            }
            fout << '\n';
        }

		fout << "Appointments:\n";

       if (patient.get_appointments().empty()) {
            fout << "No appointments\n";
        }
        else {
            for (const auto& appointment : patient.get_appointments()) {
                fout << "Doctor: " << appointment.first << ", Date: " << appointment.second << '\n';
            }
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
