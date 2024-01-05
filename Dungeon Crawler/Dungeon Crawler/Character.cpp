#include "Character.h"

const int STARTING_HEALTH = 200;
const int STARTING_DAMAGE = 10;

Character::Character(std::string name) {
	_name = name;
	_health = STARTING_HEALTH;
	_damage = STARTING_DAMAGE;
}

int Character::GetHealth() {
	return _health;
}

int Character::GetDamage() {
	return _damage;
}

std::string Character::GetName() {
	return _name;
}