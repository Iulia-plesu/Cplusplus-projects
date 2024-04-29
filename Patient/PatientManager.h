#pragma once
#include <vector>
//#include <string>
#include <fstream>
//#include <sstream>
#include "Patient.h"
//#include "Person.h"
//#include "Doctor.h"
#//include "Data.h"
class PatientManager /* : public Patient */
{
private:
	std::vector<Patient> patients;
	std::string fileName;
public:
	PatientManager(const std::string& fileName);
	
	void loadFromFile();
	void saveToFile() const;

	void set_newPatient(const Patient& patient);
	void displayPatients();


};

