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
            patientManager.readPatients(iss);
        }
        else if (type == "Doctor") {
            doctorManager.readDoctors(iss);
        }
    }
    fin.close();
}

int main() {
    PatientManager patientManager("patients.txt");
    DoctorManager doctorManager("doctors.txt");

    readFromFile("file.in", patientManager, doctorManager);

    //patientManager.displayPatients();
    //doctorManager.displayDoctors();

    return 0;
}
