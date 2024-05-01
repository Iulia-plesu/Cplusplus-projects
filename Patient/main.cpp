#include <iostream>
#include <fstream>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"
#include "PatientManager.h"
#include "DoctorManager.h"

void readFromFile(const std::string& fileName, PatientManager& patientManager, DoctorManager& doctorManager) {
    std::ifstream fin(fileName);
    if (!fin) {
        std::cerr << "Error opening file\n";
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "Patient") {
            std::string firstName, lastName, gender, medicalHistory, illnesses;
            int day, month, year, numIllnesses;

            iss >> firstName >> lastName >> day >> month >> year >> gender >> medicalHistory >> numIllnesses;

            Patient patient(firstName, lastName, day, month, year, gender, medicalHistory);

            for (int i = 0; i < numIllnesses; ++i) {
                std::string illness;
                iss >> illness;
                patient.set_familyMedicalHistory(illness);
            }

            std::string doctorFirstName, doctorLastName;
            int appointmentDay, appointmentMonth, appointmentYear;

            while (iss >> doctorFirstName >> doctorLastName >> appointmentDay >> appointmentMonth >> appointmentYear) {
                patient.set_appointment(doctorFirstName, doctorLastName, Data(appointmentDay, appointmentMonth, appointmentYear));
            }

            patientManager.set_newPatient(patient);
        }
        else if (type == "Doctor") {
            std::string firstName, lastName, gender, speciality;
            int day, month, year;

            iss >> firstName >> lastName >> day >> month >> year >> gender >> speciality;

            Data birthDate(day, month, year);
            Doctor doctor(firstName, lastName, day, month, year, gender, speciality);
            doctorManager.set_newDoctor(doctor);
        }
    }

    fin.close();
}

int main() {
    PatientManager patientManager("patients.txt");
    DoctorManager doctorManager("doctors.txt");

    readFromFile("file.in", patientManager, doctorManager);

    patientManager.displayPatients();
    doctorManager.displayDoctors();

    return 0;
}
