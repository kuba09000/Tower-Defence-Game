#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>

using namespace sf;
using namespace std;

class Bullet
{	
	//Variables
	Sprite shape;
	Vector2f direction;
	float movementSpeed;

public:

	//Constructors/Destructors
	Bullet(Texture* texture, int pos_x, int pos_y, float dir_x, float dir_y, float movement_Speed);
	~Bullet();

	//Functions
	FloatRect getGlobalBounds();

	void update();
	void render(RenderTarget* target);
};

