#include <cstdlib>

#include "Random.h"

using std::rand;

typedef Random::CharacterTypeInterval Interval;

Random::TypeSet Random::UpperTypeSet = Random::TypeSet({ Interval(65, 90) });

char Random::UpperCase()
{
	return RandomCharFromTypeSet(UpperTypeSet);
}

char Random::RandomCharFromTypeSet(TypeSet typeSet)
{
	int chosenTypeSetIndex = rand() % typeSet.Length();
	CharacterTypeInterval chosenTypeSet = typeSet[chosenTypeSetIndex];

	int interval = chosenTypeSet.end - chosenTypeSet.start;
	int chosenCharacterIndex = rand() % (interval + 1);

	return char(chosenCharacterIndex + chosenTypeSet.start);
}