#pragma once

#include <string>

using std::string;

class ArgumentParser
{
public:
	static void Initialize(int argc, char** argv);

	static bool IsHelp();
	static bool IsConfigured();
	static bool IsDefault();
	static bool HasNumber();
	static bool HasLowercase();
	static bool HasUppercase();
	static bool HasSymbol();
	static unsigned int GetLength();
	
private:
	static int amountOfArguments;
	static char** arguments;
	static int Flags;
	static unsigned int Length;

	static bool IsArgumentHelp(string arg);
	static void SetFlagHelp();

	static bool IsArgumentNumber(string arg);
	static void SetFlagNumber();

	static bool IsArgumentLowercase(string arg);
	static void SetFlagLowercase();

	static bool IsArgumentUppercase(string arg);
	static void SetFlagUppercase();

	static bool IsArgumentSymbol(string arg);
	static void SetFlagSymbol();

	static bool IsArgumentLength(string arg);
	static void SetLength(string arg);
};