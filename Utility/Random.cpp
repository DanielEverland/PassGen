#include <cstdlib>

#include "Random.h"

using std::rand;

typedef Random::CharacterTypeInterval Interval;
typedef Random::TypeSet TypeSet;

TypeSet Random::UpperTypeSet = TypeSet({ Interval(65, 90) });
TypeSet Random::LowerTypeSet = TypeSet({ Interval(97, 122) });
TypeSet Random::NumberTypeSet = TypeSet({ Interval(48, 57) });
TypeSet Random::SymbolTypeSet = TypeSet({ Interval(33, 47), Interval(58, 64), Interval(91, 96), Interval(123, 126) });

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

char Random::RandomCharFromTypeSet(TypeSet typeSet)
{
	int chosenTypeSetIndex = rand() % typeSet.Length();
	CharacterTypeInterval chosenTypeSet = typeSet[chosenTypeSetIndex];

	int interval = chosenTypeSet.end - chosenTypeSet.start;
	int chosenCharacterIndex = rand() % (interval + 1);

	return char(chosenCharacterIndex + chosenTypeSet.start);
}