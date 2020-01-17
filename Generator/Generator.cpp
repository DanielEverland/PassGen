#include <chrono>
#include <climits>

#include "Generator.h"

#include "..\Utility\Random.h"

using namespace std::chrono;

void Generator::InitializeSeed()
{
	srand(GetEpochSeed());
}

string Generator::GetPassword()
{
	string text;

	for (int i = 0; i < 100; i++)
	{
		text += Random::Symbol();
	}

	return text;
}

unsigned int Generator::GetEpochSeed()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	
	return unsigned int(ms.count() % UINT_MAX);
}