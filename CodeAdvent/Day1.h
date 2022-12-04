#pragma once

// std
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

#include "Helpers/DataReader.h";

class CalorieCounting
{
public:
	/*
	* Go through the data line by line, and storing the top 3 elves encountered so
	* far by calorie count. Advance to new elf when we meet an empty line. For
	* each elf, we compare their total calories to the current 3rd place elf, and
	* replace that elf with the current one if the current has strictly greater
	* calories. Then the new elf is sorted into the top 3. At the end, we print
	* results on the top 3 elves, including their combined toatl calorie count.
	*/
	void run()
	{
		std::vector<std::string> caloieData = FileRead::byLine("Resources/ElfCalorieData.txt");

		int runningTotal = 0;
		int elfIndex = 0;

		std::array<ElfIndexCalories, 3> elfIndexCalories = { {0, 0} };

		for (const std::string& line : caloieData)
		{
			if (line.empty())
			{
				if (runningTotal > elfIndexCalories[0].calories)
				{
					elfIndexCalories[0] =
					{
						.index = elfIndex,
						.calories = runningTotal
					};
					std::sort(std::begin(elfIndexCalories), std::end(elfIndexCalories));
				}
				runningTotal = 0;
				elfIndex++;
			}
			else
			{
				runningTotal += std::stoi(line);
			}
		}

		std::cout <<
			"The three elves with the most calories are elves number " <<
			elfIndexCalories[2].index << ", " <<
			elfIndexCalories[1].index << ", and " <<
			elfIndexCalories[0].index << " who each have a total of " <<
			elfIndexCalories[2].calories << ", " <<
			elfIndexCalories[1].calories << ", and " <<
			elfIndexCalories[0].calories << " calories respectively.\n";


		std::cout << "The combined total calories of the top three elves is " <<
			elfIndexCalories[2].calories +
			elfIndexCalories[1].calories +
			elfIndexCalories[0].calories
			<< " calories.\n";
	}

private:
	struct ElfIndexCalories
	{
		int index;
		int calories;

		bool operator<(const ElfIndexCalories& rhs) const
		{
			return calories < rhs.calories;
		}
	};
};