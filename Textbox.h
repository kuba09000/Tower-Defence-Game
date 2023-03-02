#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Textbox
{
	Text textbox;
	stringstream text;
	RectangleShape board;

	bool isSelected = false;
	bool hasLimit = false;
	int limit;

public:
	void setTextbox(int size, Color color, bool selected, Font& font, Vector2f position);
	void setLimit(bool hasLim, int lim);
	void setIsSelected(bool selected);
	void inputCharacter(int charTyped, string& nick);
	void deleteCharacter();
	void draw(RenderTarget& target);
	void update(Event ev, string& nick);
};