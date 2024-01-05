#pragma once

#include<string>

enum Sizes
{
	Small = 1,
	Medium = 2,
	Big = 3,
	TOTAL_ITEMS = 4
};

Sizes intToEnumSize(int size);

std::string GetEnumName(int size);