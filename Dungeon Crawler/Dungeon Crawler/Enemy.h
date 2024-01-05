#pragma once
#include "Sizes.h"

class Enemy {
private:
	int _health = 100;
	int _damage = 10;
	Sizes _size = Sizes::Small;

public:
	Enemy();
	Enemy(int health, int damage, Sizes size);
	int GetDamage();
	int GetHealth();
	Sizes GetSize();
	void TakeDamage(int damage);
};

Enemy CreateEnemy();