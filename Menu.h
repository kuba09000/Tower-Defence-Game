#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>

using namespace sf;
using namespace std;

class Menu
{
	int selectedItemIndex;
	Font font;
	Text text[3];
	Text selectText;
	Text moveUpText;
	Text moveDownText;
	Text escapeText;
	Texture background_tex;
	Sprite background;

	void initFont();
	void initText();
	void initTextures();
	void initSprite();
public:
	Menu();
	~Menu();

	void render(RenderTarget& target);
	void moveUp();
	void moveDown();
	int getPressedItem();
};

