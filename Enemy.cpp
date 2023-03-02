#include "Enemy.h"
#include "Game.h"


void Enemy::initTexture()
{
	this->enemy_tex[0].loadFromFile("Textures/Skun_Enemy.png");
	this->enemy_tex[1].loadFromFile("Textures/Diamond_Enemy.png");
	this->enemy_tex[2].loadFromFile("Textures/Poro_Enemy.png");
}

void Enemy::initSprite()
{
	this->shape.setTexture(enemy_tex[rand()%3]);
	this->shape.setPosition(1700, rand()% 550 + 300);
}

void Enemy::initVariables()
{
	this->direction.x = -1.f;
	if (this->shape.getTexture() == &this->enemy_tex[0]) {
		this->movementSpeed = 5.f;
		this->direction.y = 1.f;
		this->HPMax = 7;
		this->HP = HPMax;
	}
	if (this->shape.getTexture() == &this->enemy_tex[1]) {
		this->movementSpeed = 5.f;
		this->direction.y = 0.f;
		this->HPMax = 4;
		this->HP = HPMax;
	}
	if (this->shape.getTexture() == &this->enemy_tex[2]) {
		this->movementSpeed = 10.f;
		this->direction.y = 0.f;
		this->HPMax = 2;
		this->HP = HPMax;
	}
}

Enemy::Enemy()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
}

Enemy::~Enemy()
{
}

int Enemy::getHP()
{
	return this->HP;
}

int Enemy::getHPMax()
{
	return this->HPMax;
}

void Enemy::setHP(int ad)
{
	this->HP = this->HP - ad;
}

void Enemy::move()
{
	this->shape.move(this->direction * this->movementSpeed);
	if (this->shape.getPosition().y <= 300) {
		this->direction.y *= -1.f;
	}
	if (this->shape.getPosition().y >= 1000 - this->shape.getGlobalBounds().height) {
		this->direction.y *= -1.f;
	}
}

void Enemy::update()
{
	this->move();
}

void Enemy::render(RenderTarget& target)
{
	target.draw(this->shape);
}
