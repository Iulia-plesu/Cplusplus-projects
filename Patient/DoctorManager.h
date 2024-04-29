#pragma once
#include "Doctor.h"
#include "Person.h"
#include <vector>
#include<string>
#include <fstream>

class DoctorManager
{
private:
	std::vector<Doctor> doctors;
	std::string fileName;
public:
	DoctorManager(const std::string& fileName);

	void loadFromFile();
	void saveToFile() const;

	void set_newDoctor(const Doctor& doctor);

	void displayDoctors() const;
};

