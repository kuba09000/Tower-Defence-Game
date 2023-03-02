#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>

using namespace sf;
using namespace std;

class Map
{	
	//Variables
	Sprite background;
	Sprite battlefield;
	Sprite spawn;
	Texture background_tex;
	Texture battlefield_tex;
	Texture spawn_tex;
public:

	//Initialization
	void initTextures();
	void initMap();
	Map();
	~Map();

	void render(RenderTarget& target);
};

