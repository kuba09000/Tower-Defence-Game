#pragma once
#include "Ally.h"
class Alex :public Ally
{
private:
	//Initialization
	void initVariables();
	void initTexture();
	void initSprite();
	bool isAlexpicked;

public:
	
	//Constructors/Destructors
	Alex();
	~Alex();

	//Functions
	bool AlexPicked();

	const bool canAttack();
	void updatePosition();
	void updateAttack();
	void updateBullets();
	void eraseBullets();
	void update();
	void render(RenderTarget& target);
};

