#pragma once
#include <string>
#include "Person.h"
class Doctor : public Person
{
private:
    std::string speciality;

public:
    Doctor(const std::string& firstName, const std::string& lastName, int day, int month, int year, const std::string& gender, const std::string& speciality);
    ~Doctor();

    std::string get_speciality() const;
    void displayInfo() const override;
};

