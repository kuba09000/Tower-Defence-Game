#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>

using namespace sf;
using namespace std;

class Interface
{	
	//Variables
	Sprite bar_background;
	Sprite George;
	Sprite Alex;
	Sprite Matty;
	Sprite HealthPoint;
	Sprite CooldownIcon;
	vector<Sprite> HPBar;
	int points;
	int HPMax;
	
	//Resources
	Font font;
	Text points_text;
	Text George_name;
	Text Alex_name;
	Text Matty_name;
	Text George_points_needed;
	Text Alex_points_needed;
	Text Matty_points_needed;
	Text doubleAS;
	Text invalidNickText;
	Texture George_tex;
	Texture Alex_tex;
	Texture Matty_tex;
	Texture HP_tex;
	Texture bar_background_tex;
	Texture cooldown_tex;
	Texture cooldown_refresh_tex;
	
	bool george_existence = false;
	bool alex_existence = false;
	bool matty_existence = false;

public:
	//Constructors/Destructors
	Interface();
	~Interface();

	//Functions
	void setCDIcon();
	void setCDIconRefresh();
	void setPointsNull();
	void setInvalidNickTextOrigin();
	void setInvalidNickTextString();
	void setInvalidNickText_InvalidString(string nick);
	void setInvalidNickTextPosition();
	void setGeorgeExistenceFalse();
	void setAlexExistenceFalse();
	void setMattyExistenceFalse();

	int getHPBarSize();
	int getPoints();
	Text getInvalidNickText();
	bool getGeorgeExistence();
	bool getAlexExistence();
	bool getMattyExistence();

	void eraseLife();
	void addPoints(int point);
	void initVariables();
	void initTextures();
	void initFonts();
	void initText();
	void initHPBar();
	void initInterface();

	void update();
	void render(RenderTarget& target);
	void renderCDIcon(RenderTarget& target);
};

