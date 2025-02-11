#pragma once
#include <iostream>

struct Data
{
	int day, month, year;
	Data() : day(0), month(0), year(0) {}
	Data(int day, int month, int year)
		: day(day)
		, month(month)
		, year(year)
	{}

	friend std::ostream& operator<<(std::ostream& out, const Data& date)
	{
		out << date.day << "/" << date.month << "/" << date.year;
		return out;
	}
};
