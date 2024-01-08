#pragma once

#include<iostream>

//String_view

class Character
{
private:
	std::string _name;
	int _health;
	int _damage;
public:
	explicit Character(std::string name);
	int const GetHealth();
	int const GetDamage();
	std::string& GetName();
	void TakeDamage(int damage);
};
