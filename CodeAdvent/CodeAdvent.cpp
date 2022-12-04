// CodeAdvent.cpp : Defines the entry point for the application.
//

#include "CodeAdvent.h"

// solutions
#include "Day1.h"

int main()
{
	std::cout << "Enter which day you'd like to run:\n";
	int day = std::cin.get() - '0';

	switch (day)
	{
	case 1:
	{
		CalorieCounting solution{};
		solution.run();
		break;
	}
	default:
		std::cout << "Error, no such day: " << day << "\n";
		break;
	}
}
