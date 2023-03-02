#include "Alex.h"

void Alex::initVariables()
{
	this->shootCooldownMax = 60;
	this->shootCooldown = this->shootCooldownMax;

	this->isAlexpicked = false;

	this->attackDamage = 2;
}

void Alex::initTexture()
{
	this->bullet_tex.loadFromFile("Textures/Arrow.png");
	this->hero_tex.loadFromFile("Textures/Alex.png");
}

void Alex::initSprite()
{
	this->shape.setTexture(hero_tex);
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);
	this->shape.setPosition(200, 500);
}

Alex::Alex()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Alex::~Alex()
{
}

bool Alex::AlexPicked()
{
	return this->isAlexpicked;
}

const bool Alex::canAttack()
{
	if (this->shootCooldown >= this->shootCooldownMax) {
		this->shootCooldown = 0;
		return true;
	}
	return false;
}

void Alex::updatePosition()
{
	if (Mouse::isButtonPressed(Mouse::Left) && this->shape.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) && Mouse::getPosition().x < 400 - this->shape.getGlobalBounds().width / 2 && Mouse::getPosition().x>0 + this->shape.getGlobalBounds().width / 2 && Mouse::getPosition().y > 300 + this->shape.getGlobalBounds().height / 2 && Mouse::getPosition().y < 1000 - this->shape.getGlobalBounds().height / 2) {
		this->shape.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
		this->isAlexpicked = true;
	}
	else {
		this->isAlexpicked = false;
	}
}

void Alex::updateAttack()
{
	if (this->shootCooldown < this->shootCooldownMax) {
		this->shootCooldown++;
	}
}

void Alex::updateBullets()
{
	int counter = 0;
	for (int i = 0; i < this->bullets.size(); i++) {
		this->bullets[i].update();

		if (this->bullets[i].getGlobalBounds().left > 1920) {
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Alex::eraseBullets()
{
	this->bullets.clear();
}

void Alex::update()
{
	this->updateAttack();
	if (this->canAttack()) {
		this->bullets.push_back(Bullet(&bullet_tex, this->shape.getPosition().x, this->shape.getPosition().y, 1.f, 0.f, 10.f));
	}

	this->updateBullets();
}

void Alex::render(RenderTarget& target)
{
	target.draw(shape);
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
		bullets[i].render(&target);
	}
}
