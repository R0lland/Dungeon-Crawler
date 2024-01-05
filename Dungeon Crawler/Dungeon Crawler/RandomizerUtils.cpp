#include <iostream>
#include "RandomizerUtils.h"

int RandomizeMinMax(int minValue, int maxValue) {
	int randomizedValue = rand() % (maxValue - minValue + 1) + minValue;
	return randomizedValue;
}