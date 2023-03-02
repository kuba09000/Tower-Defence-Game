#pragma once
#include "Character.h"
class Enemy :public Character
{
	//Variables
	Vector2f direction;
	float movementSpeed;

	//Resources
	Texture enemy_tex[3];
	int HP;
	int HPMax;

	//Initialization
	void initVariables();
	void initTexture();
	void initSprite();

public:

	//Constructors/Destructors
	Enemy();
	~Enemy();

	//Functions
	int getHP();
	int getHPMax();

	void setHP(int ad);
	
	void move();
	void update();
	void render(RenderTarget& target);
};

