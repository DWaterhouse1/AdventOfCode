#pragma once

//std
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace FileRead
{
std::vector<std::string> byLine(const std::string& path)
{
	std::vector<std::string> buffer;

	std::fstream inFile(path);
	if (!inFile)
	{
		std::cerr << "Error opening file at " << path << "\n";
		exit(EXIT_FAILURE);
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		buffer.push_back(line);
	}
	return buffer;
}

} // namespace FileRead