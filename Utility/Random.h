#pragma once

#include <initializer_list>
#include <list>

using std::initializer_list;
using std::list;

class Random
{
public:
	struct CharacterTypeInterval;
	class TypeSet;

	static char UpperCase();
	static char RandomCharFromTypeSet(TypeSet typeSet);

	static TypeSet UpperTypeSet;

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
		TypeSet(initializer_list<CharacterTypeInterval> initList)
		{
			auto iter = initList.begin();

			while (iter != initList.end())
			{
				list.push_back(*iter);

				iter++;
			}
		}

		CharacterTypeInterval operator[](int index)
		{
			auto iter = list.begin();
			std::advance(iter, index);

			return *iter;
		}
		int Length()
		{
			return list.size();
		}

	private:
		list<CharacterTypeInterval> list;
	};
};
