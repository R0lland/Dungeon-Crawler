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