#pragma once

#include <string>

#include "..\Utility\Random.h"

using std::string;

class Generator
{
public:
	static void InitializeSeed();

	static string GetPassword(list<Random::TypeSet> list, int length);
	static unsigned int GetEpochSeed();
};