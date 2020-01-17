// PassGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Generator/Generator.h"
#include "Utility/Random.h"
#include "Utility/Clipboard.h"
#include "Utility/ArgumentParser.h"

using namespace std;

typedef Random::TypeSet TypeSet;

const int defaultLength = 100;

int main(int argc, char** argv)
{
    ArgumentParser::Initialize(argc, argv);
    Generator::InitializeSeed();

    int length = ArgumentParser::GetLength();
    if (length == 0)
        length = defaultLength;

    if (ArgumentParser::IsDefault())
    {
        string password = Generator::GetPassword(list<TypeSet>{ Random::LowerTypeSet, Random::UpperTypeSet, Random::NumberTypeSet, Random::SymbolTypeSet }, length);

        cout << password << "\n";

        if(ArgumentParser::AllowClipboard())
            Clipboard::FromString(password);
    }
    else if (ArgumentParser::IsConfigured())
    {
        list<TypeSet> typeSets;

        if (ArgumentParser::HasNumber())
        {
            typeSets.push_back(Random::NumberTypeSet);
        }
        if (ArgumentParser::HasSymbol())
        {
            typeSets.push_back(Random::SymbolTypeSet);
        }
        if (ArgumentParser::HasUppercase())
        {
            typeSets.push_back(Random::UpperTypeSet);
        }
        if (ArgumentParser::HasLowercase())
        {
            typeSets.push_back(Random::LowerTypeSet);
        }

        string password = Generator::GetPassword(typeSets, length);

        cout << password << "\n";

        if (ArgumentParser::AllowClipboard())
            Clipboard::FromString(password);
    }
    else if (ArgumentParser::IsHelp())
    {
        cout << "Help";
    }
    else
    {
        cout << "Argument not recognized";
    }
}