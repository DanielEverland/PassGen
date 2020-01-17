#pragma once

#include <string>

using std::string;

class Generator
{
public:
	static void InitializeSeed();

	static string GetPassword();
	static unsigned int GetEpochSeed();
};