#pragma once
#include "Ally.h"
class Matty :public Ally
{
private:
	//Initialization
	void initVariables();
	void initTexture();
	void initSprite();
	bool isMattypicked;

public:
	
	//Constructors/Destructors
	Matty();
	~Matty();

	//Functions
	bool MattyPicked();

	const bool canAttack();
	void updatePosition();
	void updateAttack();
	void updateBullets();
	void eraseBullets();
	void update();
	void render(RenderTarget& target);
};

