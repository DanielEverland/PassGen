#include <cstdlib>

#include "Random.h"

using std::rand;

typedef Random::CharacterTypeInterval Interval;
typedef Random::TypeSet TypeSet;

TypeSet Random::UpperTypeSet = TypeSet("UpperCase", { Interval(65, 90) });
TypeSet Random::LowerTypeSet = TypeSet("LowerCase", { Interval(97, 122) });
TypeSet Random::NumberTypeSet = TypeSet("Numbers", { Interval(48, 57) });
TypeSet Random::SymbolTypeSet = TypeSet("Symbols", { Interval(33, 47), Interval(58, 64), Interval(91, 96), Interval(123, 126) });


char Random::UpperCase()
{
	return RandomCharFromTypeSet(UpperTypeSet);
}

char Random::LowerCase()
{
	return RandomCharFromTypeSet(LowerTypeSet);
}

char Random::Number()
{
	return RandomCharFromTypeSet(NumberTypeSet);
}

char Random::Symbol()
{
	return RandomCharFromTypeSet(SymbolTypeSet);
}

string Random::RandomStringFromTypeSets(list<TypeSet> typeSets, int length)
{
	string text;
	list<TypeSet>::iterator iter;
	TypeSet* chosenTypeSet;
	int chosenTypeSetIndex;
	int interval;

	for (int i = 0; i < length; i++)
	{
		chosenTypeSetIndex = rand() % typeSets.size();

		iter = typeSets.begin();
		std::advance(iter, chosenTypeSetIndex);

		text += RandomCharFromTypeSet(*iter);
	}

	return text;
}

char Random::RandomCharFromTypeSet(TypeSet typeSet)
{
	int chosenTypeSetIndex = rand() % typeSet.Length();
	CharacterTypeInterval chosenTypeSet = typeSet[chosenTypeSetIndex];

	int interval = chosenTypeSet.end - chosenTypeSet.start;
	int chosenCharacterIndex = rand() % (interval + 1);

	return char(chosenCharacterIndex + chosenTypeSet.start);
}