#include<iostream>
#include "Character.h"

Character::Character(std::string _name, float _health, float _damage) {
	name = _name;
	health = _health;
	damage = _damage;
}

void Character::Attack(Character& enemy) {
	enemy.health -= damage;
	if (enemy.health <= 0) {
		std::cout << name << " attacked " << enemy.name << " and killed " << enemy.name << std::endl;
	}
	else {
		std::cout << name << " attacked " << enemy.name << " and dealt " << damage << " damage." << enemy.name << " health: " << enemy.health << std::endl;
	}
}