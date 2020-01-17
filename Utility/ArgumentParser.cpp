#include <cstdlib>
#include <string>
#include <iostream>

#include "ArgumentParser.h"

int ArgumentParser::amountOfArguments = 0;
char** ArgumentParser::arguments = 0;
int ArgumentParser::Flags = 0;
unsigned int ArgumentParser::Length = 0;

void ArgumentParser::Initialize(int argc, char** argv)
{
	ArgumentParser::amountOfArguments = argc;
	ArgumentParser::arguments = argv;

	for (int i = 0; i < amountOfArguments; i++)
	{
		string arg = argv[i];

		if (IsArgumentHelp(arguments[i]))
		{
			SetFlagHelp();
		}
		if (IsArgumentNumber(arguments[i]))
		{
			SetFlagNumber();
		}
		if (IsArgumentLowercase(arguments[i]))
		{
			SetFlagLowercase();
		}
		if (IsArgumentUppercase(arguments[i]))
		{
			SetFlagUppercase();
		}
		if (IsArgumentSymbol(arguments[i]))
		{
			SetFlagSymbol();
		}
		if (IsArgumentDisableClipboard(arguments[i]))
		{
			SetFlagDisableClipboard();
		}
		if (IsArgumentLength(arguments[i]))
		{
			SetLength(arguments[i]);
		}
	}
}

bool ArgumentParser::HasNumber()
{
	return Flags & 1 << 1;
}

bool ArgumentParser::HasLowercase()
{
	return Flags & 1 << 2;
}

bool ArgumentParser::HasUppercase()
{
	return Flags & 1 << 3;
}

bool ArgumentParser::HasSymbol()
{
	return Flags & 1 << 4;
}

bool ArgumentParser::AllowClipboard()
{
	return !(Flags & 1 << 5);
}

bool ArgumentParser::IsHelp()
{
	return Flags & 1 << 0;
}

bool ArgumentParser::IsConfigured()
{
	return HasNumber() || HasLowercase() || HasUppercase() || HasSymbol();
}

bool ArgumentParser::IsDefault()
{
	return !IsConfigured();
}

unsigned int ArgumentParser::GetLength()
{
	return Length;
}

bool ArgumentParser::IsArgumentHelp(string arg)
{
	return arg == "-h";
}

void ArgumentParser::SetFlagHelp()
{
	Flags |= 1 << 0;
}

bool ArgumentParser::IsArgumentNumber(string arg)
{
	return arg == "-n";
}

void ArgumentParser::SetFlagNumber()
{
	Flags |= 1 << 1;
}

bool ArgumentParser::IsArgumentLowercase(string arg)
{
	return arg == "-l";
}

void ArgumentParser::SetFlagLowercase()
{
	Flags |= 1 << 2;
}

bool ArgumentParser::IsArgumentUppercase(string arg)
{
	return arg == "-u";
}

void ArgumentParser::SetFlagUppercase()
{
	Flags |= 1 << 3;
}

bool ArgumentParser::IsArgumentSymbol(string arg)
{
	return arg == "-s";
}

void ArgumentParser::SetFlagSymbol()
{
	Flags |= 1 << 4;
}

bool ArgumentParser::IsArgumentLength(string arg)
{
	for (int i = 0; i < arg.length(); i++)
	{
		if (!isdigit(arg[i]))
			return false;
	}

	return true;
}

void ArgumentParser::SetLength(string arg)
{
	Length = std::stoi(arg);
}

bool ArgumentParser::IsArgumentDisableClipboard(string arg)
{
	return arg == "-c";
}

void ArgumentParser::SetFlagDisableClipboard()
{
	Flags |= 1 << 5;
}