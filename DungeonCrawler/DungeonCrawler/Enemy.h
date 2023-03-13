#pragma once

#include "Character.h"
#include "Sizes.h"

class Enemy : public Character {
public:
	Enemy() : Character() {}
	Enemy(int _id, std::string name, float health, float damage, Sizes _size) : Character(name, health, damage) {
		id = _id;
		size = _size;
	}

	int id;
	Sizes size = Sizes::Small;
};