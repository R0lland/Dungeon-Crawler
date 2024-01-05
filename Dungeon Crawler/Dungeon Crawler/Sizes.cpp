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

int EnumSizeToInt(Sizes size) {
	switch (size)
	{
	case Sizes::Small:
		return 1;
	case Sizes::Medium:
		return 2;
	case Sizes::Big:
		return 3;
	case Sizes::TOTAL_ITEMS:
		return 4;
	}
	return 0;
}