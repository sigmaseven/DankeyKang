#include "ROM.h"

ROM::ROM(){}

bool ROM::Open(std::string fileName)
{
	uint32_t length;
	input.open(fileName, std::ifstream::in | std::ios::binary);

	if (!input.is_open())
	{
		return false;
	}

	length = GetRomSize();
	data.resize(length);

	input.seekg(0, input.beg);

	for (int i = 0; i < data.size(); i++)
	{
		input.read((char *)&data[i], 1);
	}
	printf("Magic: %x\n", GetMagic());
	return true;
}

void ROM::Close()
{
	if (input.is_open())
	{
		input.close();
	}
}

void ROM::Clear()
{
	if (data.size() > 0)
	{
		data.clear();
	}
}

uint32_t ROM::GetRomSize()
{
	uint32_t length;

	if (input.is_open())
	{
		input.seekg(0, input.end);
		length = (uint32_t)input.tellg();
		input.seekg(0, input.beg);
		return length;
	}
	return 0;
}

uint32_t ROM::GetMagic()
{
	if (data.size() > 0 && data.size() > 3)
	{
		return((uint32_t)(data[0] << 24 | data[1] << 16 | data[2] << 8 | data[3]));
	}
	return (uint32_t)0;
}

bool ROM::CheckMagic()
{
	if (data.size() > 0 && GetMagic() == 0x4e45531a)
	{
		return true;
	}
	return false;
}