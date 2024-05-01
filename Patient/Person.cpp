#include "Person.h"

int Person::calculateAge() const
{
    auto currentTime = std::chrono::system_clock::now();

    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

    std::tm localTime;
    localtime_s(&localTime, &currentTimeT);

    int age = localTime.tm_year + 1900 - birthDate.year;
    if (localTime.tm_mon < birthDate.month - 1 || (localTime.tm_mon == birthDate.month - 1 && localTime.tm_mday < birthDate.day)) {
        age--;
    }

    return age;
}

Person::Person(const std::string& firstName, const std::string& lastName, const Data& birthDate, const std::string& gender)
	: firstName(firstName)
	, lastName(lastName)
	, birthDate(birthDate)
	, gender(gender)
{}

Person::~Person()
{}

std::string Person::get_name() const
{
	return firstName + " " + lastName;
}

std::string Person::get_gender() const
{
	return gender;
}


int Person::get_age() const
{
	return calculateAge();
}

