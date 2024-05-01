#include "Doctor.h"

Doctor::Doctor(const std::string& firstName, const std::string& lastName, int day, int month, int year, const std::string& gender, const std::string& speciality)
    : Person(firstName, lastName, Data(day, month, year), gender)
    , speciality(speciality)
{}

Doctor::~Doctor()
{}

std::string Doctor::get_speciality() const
{
    return speciality;
}

void Doctor::displayInfo() const
{
    std::cout << "Name: " << get_name() << '\n';
    std::cout << "Age: " << get_age() << '\n';
    std::cout << "Gender: " << get_gender() << '\n';
    std::cout << "Speciality: " << speciality << '\n';
}
