#pragma once
#include "Character.h"
#include "Bullet.h"
class Ally :public Character
{
public:
	vector<Bullet> bullets;
	//Resources
	Texture bullet_tex;
	Texture hero_tex;

	//Variables
	int shootCooldown;
	int shootCooldownMax;

	int attackDamage;
};

