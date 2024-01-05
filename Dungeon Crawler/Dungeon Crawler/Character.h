#pragma once
class Character
{
private:
	int _health;
	int _damage;
public:
	int GetHealth() {
		return _health;
	}
	int GetDamage() {
		return _damage;
	}
};
