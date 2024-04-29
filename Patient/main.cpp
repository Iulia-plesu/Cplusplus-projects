
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"
#include "PatientManager.h"
#include "DoctorManager.h"


int main() {
    PatientManager patientManager("patients.txt");
    DoctorManager doctorManager("doctors.txt");

    Patient patient1("John", "Doe", 35, "Male", "None");
    patient1.set_familyMedicalHistory("Diabetes");
    patient1.set_appointment("Dr.", "Smith", Data(24, 5, 2024));
    patientManager.set_newPatient(patient1);

    Patient patient2("Jane", "Smith", 28, "Female", "Allergies");
    patient2.set_familyMedicalHistory("Heart disease");
    patient2.set_appointment("Dr.", "Johnson", "2024-04-29");
    patientManager.set_newPatient(patient2);

    Doctor doctor1("Dr.", "Smith", 45, "Male", "Cardiologist");
    doctorManager.set_newDoctor(doctor1);

    Doctor doctor2("Dr.", "Johnson", 38, "Female", "Dermatologist");
    doctorManager.set_newDoctor(doctor2);


    patientManager.displayPatients();
    doctorManager.displayDoctors();

    return 0;
}