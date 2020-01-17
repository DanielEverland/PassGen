#include <chrono>
#include <climits>
#include <list>

#include "Generator.h"

#include "..\Utility\Random.h"

typedef Random::TypeSet TypeSet;

using namespace std::chrono;

using std::list;

void Generator::InitializeSeed()
{
	srand(GetEpochSeed());
}

string Generator::GetPassword()
{
	list<TypeSet> typeSets{ Random::LowerTypeSet, Random::UpperTypeSet, Random::NumberTypeSet, Random::SymbolTypeSet };

	return Random::RandomStringFromTypeSets(typeSets, 100);
}

unsigned int Generator::GetEpochSeed()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	
	return unsigned int(ms.count() % UINT_MAX);
}