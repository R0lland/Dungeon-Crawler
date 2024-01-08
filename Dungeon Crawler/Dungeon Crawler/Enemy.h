#pragma once
#include "Sizes.h"
#include <iostream>
#include <vector>

class Enemy {
private:
	int _health = 100;
	int _damage = 10;
	Sizes _size = Sizes::Small;

public:
	Enemy(int health, int damage, Sizes size);
	int GetDamage();
	int GetHealth();
	Sizes& GetSize();
	void TakeDamage(int damage);
};

void CreateEnemies(int numberOfEnemies, std::vector<Enemy>& enemies);