#include "George.h"
#include "Map.h"

void George::initVariables()
{
	this->shootCooldownMax = 30;
	this->shootCooldown = this->shootCooldownMax;

	this->isGeorgepicked = false;

	this->attackDamage = 1;
}

void George::initTexture()
{
	this->bullet_tex.loadFromFile("Textures/Boomerang.png");
	this->hero_tex.loadFromFile("Textures/George.png");
}

void George::initSprite()
{
	this->shape.setTexture(hero_tex);
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);
	this->shape.setPosition(200, 700);
}

George::George()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

George::~George()
{
}

bool George::getGeorgePicked()
{
	return this->isGeorgepicked;
}

const bool George::canAttack()
{
	if (this->shootCooldown >= this->shootCooldownMax) {
		this->shootCooldown = 0;
		return true;
	}
	return false;
}


void George::updatePosition()
{
	if (Mouse::isButtonPressed(Mouse::Left) && this->shape.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) && Mouse::getPosition().x < 400 - this->shape.getGlobalBounds().width / 2 && Mouse::getPosition().x>0 + this->shape.getGlobalBounds().width / 2 && Mouse::getPosition().y > 300 + this->shape.getGlobalBounds().height / 2 && Mouse::getPosition().y < 1000 - this->shape.getGlobalBounds().height / 2) {
		this->shape.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
		this->isGeorgepicked = true;
	}
	else {
		this->isGeorgepicked = false;
	}
}

void George::updateAttack()
{	
	if (this->shootCooldown < this->shootCooldownMax) {
		this->shootCooldown++;
	}
}

void George::updateBullets()
{
	int counter = 0;
	for (int i = 0; i < this->bullets.size();i++) {
		this->bullets[i].update();

		if (this->bullets[i].getGlobalBounds().left > 1920) {
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void George::eraseBullets()
{
	this->bullets.clear();
}

void George::update()
{	
	//Shooting
	this->updateAttack();
	if (this->canAttack()) {
		this->bullets.push_back(Bullet(&bullet_tex, this->shape.getPosition().x, this->shape.getPosition().y,1.f,0.f,10.f));
	}

	this->updateBullets();
}

void George::render(RenderTarget& target)
{
	target.draw(shape);
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
		bullets[i].render(&target);
	}
}
