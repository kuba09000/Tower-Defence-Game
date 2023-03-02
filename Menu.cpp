#include "Menu.h"

void Menu::initFont()
{
	if (!font.loadFromFile("Fonts/Badaboom.ttf")) {
		cout << "Error loading font" << endl;
	}
}

void Menu::initText()
{
	this->text[0].setFont(this->font);
	this->text[0].setCharacterSize(50);
	this->text[0].setFillColor(Color::Red);
	this->text[0].setString("Play");
	this->text[0].setPosition(900, 200);

	this->text[1].setFont(this->font);
	this->text[1].setCharacterSize(50);
	this->text[1].setFillColor(Color::White);
	this->text[1].setString("Ranking");
	this->text[1].setPosition(900, 400);

	this->text[2].setFont(this->font);
	this->text[2].setCharacterSize(50);
	this->text[2].setFillColor(Color::White);
	this->text[2].setString("Quit");
	this->text[2].setPosition(900, 600);

	this->selectText.setFont(this->font);
	this->selectText.setCharacterSize(30);
	this->selectText.setFillColor(Color::White);
	this->selectText.setString("(ENTER) - Select");
	this->selectText.setPosition(100, 1000);

	this->moveDownText.setFont(this->font);
	this->moveDownText.setCharacterSize(30);
	this->moveDownText.setFillColor(Color::White);
	this->moveDownText.setString("(DOWN) - Move Down");
	this->moveDownText.setPosition(100 + this->selectText.getGlobalBounds().width +50, 1000);

	this->moveUpText.setFont(this->font);
	this->moveUpText.setCharacterSize(30);
	this->moveUpText.setFillColor(Color::White);
	this->moveUpText.setString("(UP) - Move Up");
	this->moveUpText.setPosition(100 + this->selectText.getGlobalBounds().width + this->moveDownText.getGlobalBounds().width +100, 1000);

	this->escapeText.setFont(this->font);
	this->escapeText.setCharacterSize(30);
	this->escapeText.setFillColor(Color::White);
	this->escapeText.setString("(ESC) - Leave Game");
	this->escapeText.setPosition(100 + this->selectText.getGlobalBounds().width + this->moveDownText.getGlobalBounds().width + this->moveUpText.getGlobalBounds().width + 150, 1000);
}

void Menu::initTextures()
{
	this->background_tex.loadFromFile("Textures/Background.jpg");
}

void Menu::initSprite()
{
	this->background.setTexture(background_tex);
}

Menu::Menu()
{
	this->initFont();
	this->initText();
	this->initTextures();
	this->initSprite();
}

Menu::~Menu()
{
}


void Menu::render(RenderTarget& target)
{
	target.draw(this->background);
	for (int i = 0; i < 3; i++) {
		target.draw(this->text[i]);
	}
	target.draw(this->selectText);
	target.draw(this->moveDownText);
	target.draw(this->moveUpText);
}

void Menu::moveUp()
{
	if (this->selectedItemIndex - 1 >= 0) {
		text[this->selectedItemIndex].setFillColor(Color::White);
		this->selectedItemIndex--;
		text[this->selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::moveDown()
{
	if (this->selectedItemIndex + 1 <3) {
		text[this->selectedItemIndex].setFillColor(Color::White);
		this->selectedItemIndex++;
		text[this->selectedItemIndex].setFillColor(Color::Red);
	}
}

int Menu::getPressedItem()
{
	return this->selectedItemIndex;
}
