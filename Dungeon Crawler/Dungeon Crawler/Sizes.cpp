#include "Sizes.h"

Sizes intToEnumSize(int size) {
	switch (size)
	{
	case 1:
		return Sizes::Small;
	case 2:
		return Sizes::Medium;
	case 3:
		return Sizes::Big;
	case 4:
		return Sizes::TOTAL_ITEMS;
	}

	return Sizes::Small;
}

std::string GetEnumName(int size)
{
	switch (size)
	{
	case 1:
		return "Small";
	case 2:
		return "Medium";
	case 3:
		return "Big";
	case 4:
		return "TOTAL";
	}

	return "Unassigned";
}
