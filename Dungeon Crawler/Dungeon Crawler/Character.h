#pragma once

#include<iostream>

class Character
{
private:
	std::string _name;
	int _health;
	int _damage;
public:
	Character(std::string name);
	int GetHealth();
	int GetDamage();
	std::string GetName();
	void TakeDamage(int damage);
};
