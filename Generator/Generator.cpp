#include <chrono>
#include <climits>
#include <list>
#include <iostream>
#include <string>

#include "Generator.h"

#include "..\Utility\Random.h"
#include "..\Utility\Clipboard.h"

typedef Random::TypeSet TypeSet;

using namespace std::chrono;

using std::list;
using std::cout;

void Generator::InitializeSeed()
{
	srand(GetEpochSeed());
}

string Generator::GetPassword(list<TypeSet> list, int length)
{
	cout << "\n";
	cout << "Generating Password" << "\n";

	OutputOptions(list, length);

	return Random::RandomStringFromTypeSets(list, length);
}

unsigned int Generator::GetEpochSeed()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	
	return unsigned int(ms.count() % UINT_MAX);
}

void Generator::OutputOptions(list<TypeSet> list, int length)
{
	cout << "Typesets: ";

	auto iter = list.begin();
	while (iter != list.end())
	{
		cout << (*iter).GetName() << " ";

		iter++;
	}

	cout << "\n";

	cout << "Length: " << std::to_string(length) << "\n";
}