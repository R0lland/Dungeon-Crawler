#pragma once
#include "Sizes.h"

class Enemy {
private:
	int _health;
	int _damage;
	Sizes _size;

public:
	void Setup();
	int GetDamage() {
		return _damage;
	};
	int GetHealth() {
		return _health;
	};
};