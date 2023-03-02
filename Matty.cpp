#include "Matty.h"

void Matty::initVariables()
{
	this->shootCooldownMax = 90;
	this->shootCooldown = this->shootCooldownMax;

	this->isMattypicked = false;

	this->attackDamage = 3;
}

void Matty::initTexture()
{
	this->bullet_tex.loadFromFile("Textures/Bullet.png");
	this->hero_tex.loadFromFile("Textures/Matty.png");
}

void Matty::initSprite()
{
	this->shape.setTexture(hero_tex);
	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);
	this->shape.setPosition(200, 500);
}

Matty::Matty()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Matty::~Matty()
{
}

bool Matty::MattyPicked()
{
	return this->isMattypicked;
}

const bool Matty::canAttack()
{
	if (this->shootCooldown >= this->shootCooldownMax) {
		this->shootCooldown = 0;
		return true;
	}
	return false;
}

void Matty::updatePosition()
{
	if (Mouse::isButtonPressed(Mouse::Left) && this->shape.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) && Mouse::getPosition().x < 400 - this->shape.getGlobalBounds().width / 2 && Mouse::getPosition().x>0 + this->shape.getGlobalBounds().width / 2 && Mouse::getPosition().y > 300 + this->shape.getGlobalBounds().height / 2 && Mouse::getPosition().y < 1000 - this->shape.getGlobalBounds().height / 2) {
		this->shape.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
		this->isMattypicked = true;
	}
	else {
		this->isMattypicked = false;
	}
}

void Matty::updateAttack()
{
	if (this->shootCooldown < this->shootCooldownMax) {
		this->shootCooldown++;
	}
}

void Matty::updateBullets()
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

void Matty::eraseBullets()
{
	this->bullets.clear();
}

void Matty::update()
{
	//Shooting
	this->updateAttack();
	if (this->canAttack()) {
		this->bullets.push_back(Bullet(&bullet_tex, this->shape.getPosition().x, this->shape.getPosition().y, 1.f, 0.f, 10.f));
	}

	this->updateBullets();
}

void Matty::render(RenderTarget& target)
{
	target.draw(shape);
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
		bullets[i].render(&target);
	}
}
