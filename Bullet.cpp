#include "Bullet.h"

Bullet::Bullet(Texture* texture, int pos_x, int pos_y, float dir_x, float dir_y, float movement_Speed)
{
	this->shape.setTexture(*texture);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_Speed;
	this->shape.setPosition(pos_x, pos_y);
}

Bullet::~Bullet()
{

}

FloatRect Bullet::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(RenderTarget* target)
{
	target->draw(this->shape);
}
