#include "Character.h"

Character::Character(std::string name, int health, int damage) {
	_name = name;
	_health = health;
	_damage = damage;
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