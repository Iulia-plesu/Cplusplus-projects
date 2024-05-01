#include "PatientManager.h"

PatientManager::PatientManager(const std::string& fileName)
    : fileName(fileName)
{}

void PatientManager::readPatients(std::istringstream& iss)
{
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
    this->set_newPatient(patient);
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
/*
void PatientManager::displayPatients()
{
    std::cout << "Patients:\n";
    for (const auto& patient : patients) {
        patient.displayInfo();
        std::cout << "\n";
    }
}
*/
