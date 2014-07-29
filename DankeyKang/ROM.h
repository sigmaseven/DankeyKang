#pragma once

#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct rom_header
{
	char magic[4];
	uint8_t program_entries;
	uint8_t sprite_entries;
	uint8_t screen_flags;
	uint8_t system_flags;
	uint8_t ram_size;
	uint8_t flags_9;
	uint8_t flags_10;
	uint32_t reserved;
};

enum tv_encoding
{
	NTSC = 0x00,
	PAL  = 0x01 
};

class ROM
{
private:
	// Pointer for ROM data that we will allocate in heap.
	std::vector<uint8_t> data;

	// Pointer for position in ROM data.
	uint8_t *position;

	// File stream for ROM input
	std::ifstream input;

	// File stream for ROM output
	std::ofstream output;

	uint32_t index;

public:
	ROM();
	ROM(std::string fileName);
	bool Open(std::string fileName);
	void Close();
	void Clear();
	void Parse();
	uint32_t GetRomSize();
	uint32_t GetMagic();
	bool CheckMagic();
	void Seek(uint32_t position);
	uint8_t GetPRGBanks();
	uint8_t GetCHRBanks();
	uint32_t GetPRGBankSize();
	uint32_t GetCHRBankSize();
	bool IsTrainerPresent();
	bool IsBatteryPresent();
	tv_encoding GetEncoding();
};