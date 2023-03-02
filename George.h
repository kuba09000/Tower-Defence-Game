#pragma once
#include "Ally.h"
#include <thread>
#include <chrono>

class George :public Ally
{
private:
	//Initialization
	void initVariables();
	void initTexture();
	void initSprite();
	bool isGeorgepicked;

public:

	//Constructors/Destructors
	George();
	~George();

	//Functions

	bool getGeorgePicked();

	const bool canAttack();
	void updatePosition();
	void updateAttack();
	void updateBullets();
	void eraseBullets();
	void update();
	void render(RenderTarget& target);
};

