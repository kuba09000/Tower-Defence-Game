#include "Map.h"

void Map::initTextures()
{
	this->background_tex.loadFromFile("Textures/Game_Background.jpg");
	this->battlefield_tex.loadFromFile("Textures/Battlefield.jpg");
	this->spawn_tex.loadFromFile("Textures/Spawn.jpg");
}

void Map::initMap()
{
	this->background.setTexture(background_tex);
	this->battlefield.setTexture(battlefield_tex);
	this->spawn.setTexture(spawn_tex);
	this->battlefield.setPosition(0, 300);
	this->spawn.setPosition(0, 300);
}

Map::Map()
{
	this->initTextures();
	this->initMap();
}

Map::~Map()
{
}


void Map::render(RenderTarget& target)
{
	target.draw(this->background);
	target.draw(this->battlefield);
	target.draw(this->spawn);
}
