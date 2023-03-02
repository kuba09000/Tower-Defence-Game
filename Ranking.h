#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <filesystem>
#include <fstream>
#include <ranges>
#include "Textbox.h"

using namespace sf;
using namespace std;

class Ranking
{	
	//Variables
	Font font;
	Text rankingText;
	Text escapeText;
	Text saveText;
	Text gameOverText;
	vector<pair<int, string>> rankingVector;
	Text listScoreboard;
	Sprite background;
	Texture background_tex;
	Textbox textbox;
public:


	//Initialization
	void initFont();
	void initText();
	void initTexture();
	void initSprite();
	void initTextbox();
	void initScoreboard(string text, Vector2f pos);
	
	//Constructors/Destructors
	Ranking();
	~Ranking();

	//Functions
	bool correctNick(string nick);
	void loadRanking();
	int rankingVectorSize();
	void showRanking(RenderTarget& target);
	void saveToFile(string nick, int score);
	void update();
	void updateTextbox(Event ev, string& nick);
	void render(RenderTarget& target);
	void renderTextbox(RenderTarget& target);
};

