#include "Doctor.h"

Doctor::Doctor(const std::string& firstName, const std::string& lastName, Data birthDate, const std::string& gender, const std::string& speciality)
    : Person(firstName, lastName, birthDate, gender)
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
