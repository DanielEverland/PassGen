#pragma once

#include <string>

#include "..\Utility\Random.h"

using std::string;

class Generator
{
public:
	static void InitializeSeed();

	static string GetPassword(list<Random::TypeSet> list, int length);

private:
	static unsigned int GetEpochSeed();
	static void OutputOptions(list<Random::TypeSet> list);
};