#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "Patient.h"
class PatientManager 
{
private:
	std::vector<Patient> patients;
	std::string fileName;
public:
	PatientManager(const std::string& fileName);
	
	void readPatients(std::istringstream& iss);
	void saveToFile() const;

	void set_newPatient(const Patient& patient);
	void displayPatients();


};

