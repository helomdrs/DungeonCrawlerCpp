#pragma once
#include <string>

class Character {

public:
	Character() {};
	Character(std::string _name, float _health, float _damage);

	std::string name;
	float health;
	float damage;

	void Attack(Character& character);
};