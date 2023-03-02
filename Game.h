#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <chrono>

#include "Map.h"
#include "George.h"
#include "Matty.h"
#include "Alex.h"
#include "Bullet.h"
#include "Interface.h"
#include "Enemy.h"
#include "Menu.h"
#include "Ranking.h"
#include "Textbox.h"

using namespace sf;
using namespace std;

class Game
{
private:
	//Variables
	RenderWindow *window;
	Event sfEvent;
	string nick;

	//Resources
	Menu menu;
	Map map;
	Ranking ranking;

	//Characters
	George george;
	Alex alex;
	Matty matty;
	vector<Enemy*> enemies;

	//Game logic
	int enemySpawnTimerMax;
	int enemySpawnTimer;
	bool abilityCastThread;
	unsigned int gameState;
	unsigned int menuState;
	unsigned int rankingState;
	Interface interface;
	float Frames;

	//Initialization
	void initWindow();
	void initVariables();

public:

	//Constructor/Destructor
	Game();
	~Game();

	//Functions
	void abilityDuration(bool& threadFree);
	void updateSFMLEvents();
	void updateInterface();
	void updateGeorge();
	void updateAlex();
	void updateMatty();
	float countFrames();
	void spawnEnemy(bool& threadFree);
	void updateEnemies();
	void deleteEnemies();
	void deleteBullets();
	void update();
	void render();
	void gameOver();
	void renderGameOver();
	void restartGame();
	void run();
};

