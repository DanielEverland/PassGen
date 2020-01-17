// PassGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Generator/Generator.h"

int main()
{
    Generator::InitializeSeed();

    std::cout << Generator::GetPassword();
}