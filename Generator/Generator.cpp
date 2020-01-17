#include <chrono>
#include <climits>
#include <list>
#include <iostream>

#include "Generator.h"

#include "..\Utility\Random.h"
#include "..\Utility\Clipboard.h"

typedef Random::TypeSet TypeSet;

using namespace std::chrono;

using std::list;

void Generator::InitializeSeed()
{
	srand(GetEpochSeed());
}

string Generator::GetPassword(list<TypeSet> list, int length)
{
	return Random::RandomStringFromTypeSets(list, length);
}

unsigned int Generator::GetEpochSeed()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	
	return unsigned int(ms.count() % UINT_MAX);
}