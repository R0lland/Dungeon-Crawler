#include "Enemy.h"
#include "RandomizerUtils.h"
#include <vector>
#include <iostream>

const int MIN_DAMAGE = 10;
const int MAX_DAMAGE = 20;
const int MIN_HEALTH = 100;
const int MAX_HEALTH = 200;

Enemy::Enemy(int health, int damage, Sizes size) {
	_health = health;
	_damage = damage;
	_size = size;
}

int Enemy::GetHealth() {
	return _health;
}

int Enemy::GetDamage() {
	return _damage;
}

Sizes& Enemy::GetSize() {
	return _size;
}

void Enemy::TakeDamage(int damage) {
	_health -= damage;
}

void CreateEnemies(int numberOfEnemies, std::vector<Enemy>& enemies) {
	enemies.reserve(numberOfEnemies);
	for (int i = 0; i < numberOfEnemies; i++)
	{
		int health = RandomizeMinMax(MIN_HEALTH, MAX_HEALTH);
		int damage = RandomizeMinMax(MIN_DAMAGE, MAX_DAMAGE);
		int sizeInt = RandomizeMinMax(1, Sizes::TOTAL_ITEMS - 1);
		enemies.emplace_back(health, damage, intToEnumSize(sizeInt));
	}
}
