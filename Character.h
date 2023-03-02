#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Character
{
public:
	//Variables
	Sprite shape;

	//Texture texture;
	virtual void update() = 0;
	virtual void render(RenderTarget& target) = 0;
};

