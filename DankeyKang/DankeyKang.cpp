// DankeyKang.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "ROM.h"
#include "PRNG.h"

int main(int argc, char *argv[])
{
	ROM rom;
	rom.Open("dkong.nes");

	printf("Rom size: %d\n", rom.GetRomSize());
	printf("PRG: %d\n", rom.GetPRGBanks());
	printf("CHR: %x\n", rom.GetCHRBanks());

	if (rom.CheckMagic())
	{
		std::cout << "Magic check passed.\n";
	}
	else
	{
		std::cout << "Magic check failed.\n";
	}

	return 0;
}

