#include "Enemy.h"
#include "RandomizerUtils.h"

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

Enemy Enemy::CreateEnemy() {
	int health = RandomizeMinMax(MIN_HEALTH, MAX_HEALTH);
	int damage = RandomizeMinMax(MIN_DAMAGE, MAX_DAMAGE);
	int sizeInt = RandomizeMinMax(1, EnumSizeToInt(Sizes::TOTAL_ITEMS));
	return Enemy(health, damage, intToEnumSize(sizeInt));
}