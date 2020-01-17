#pragma once

#include <initializer_list>
#include <list>
#include <string>

using std::initializer_list;
using std::string;
using std::list;

class Random
{
public:
	struct CharacterTypeInterval;
	class TypeSet;

	static list<TypeSet> AllTypeSets;
	static TypeSet UpperTypeSet;
	static TypeSet LowerTypeSet;
	static TypeSet NumberTypeSet;
	static TypeSet SymbolTypeSet;

	static string RandomStringFromTypeSets(list<TypeSet> typeSets, int length);
	static char UpperCase();
	static char LowerCase();
	static char Number();
	static char Symbol();
	static char RandomCharFromTypeSet(TypeSet typeSet);

	struct CharacterTypeInterval
	{
	public:
		CharacterTypeInterval(unsigned int start, unsigned int end)
		{
			this->start = start;
			this->end = end;
		}

		unsigned int start;
		unsigned int end;
	};

	class TypeSet
	{
	public:
		TypeSet(string name, initializer_list<CharacterTypeInterval> initList)
		{
			this->name = name;

			auto iter = initList.begin();

			while (iter != initList.end())
			{
				list.push_back(*iter);

				iter++;
			}
		}

		CharacterTypeInterval operator[](int index) const
		{
			auto iter = list.begin();
			std::advance(iter, index);

			return *iter;
		}
		int Length() const
		{
			return list.size();
		}
		string GetName() const
		{
			return name;
		}

	private:
		list<CharacterTypeInterval> list;
		string name;
	};
};
