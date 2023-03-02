#include "Interface.h"

void Interface::initVariables()
{
	this->points = 0;
	this->HPMax = 3;
}

void Interface::initTextures()
{
	this->George_tex.loadFromFile("Textures/George.png");
	this->Alex_tex.loadFromFile("Textures/Alex.png");
	this->Matty_tex.loadFromFile("Textures/Matty.png");
	this->HP_tex.loadFromFile("Textures/Heart.png");
	this->bar_background_tex.loadFromFile("Textures/Bar.jpg");
	this->cooldown_tex.loadFromFile("Textures/Cooldown_available.png");
	this->cooldown_refresh_tex.loadFromFile("Textures/Cooldown_navailable.png");
}

void Interface::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Badaboom.ttf")) {
		cout << "Error loading font" << endl;
	}
}

void Interface::initText()
{
	this->points_text.setFont(this->font);
	this->points_text.setCharacterSize(40);
	this->points_text.setFillColor(Color::White);

	this->George_name.setFont(this->font);
	this->George_name.setCharacterSize(30);
	this->George_name.setString("George");
	this->George_name.setOrigin(this->George_name.getGlobalBounds().width / 2, this->George_name.getGlobalBounds().height / 2);
	this->George_name.setPosition(this->George.getPosition().x + this->George.getGlobalBounds().width / 2, this->bar_background.getPosition().y + 25);

	this->Alex_name.setFont(this->font);
	this->Alex_name.setCharacterSize(30);
	this->Alex_name.setString("Alex");
	this->Alex_name.setOrigin(this->Alex_name.getGlobalBounds().width / 2, this->Alex_name.getGlobalBounds().height / 2);
	this->Alex_name.setPosition(this->Alex.getPosition().x + this->Alex.getGlobalBounds().width / 2, this->bar_background.getPosition().y + 25);

	this->Matty_name.setFont(this->font);
	this->Matty_name.setCharacterSize(30);
	this->Matty_name.setString("Matty");
	this->Matty_name.setOrigin(this->Matty_name.getGlobalBounds().width / 2, this->Matty_name.getGlobalBounds().height / 2);
	this->Matty_name.setPosition(this->Matty.getPosition().x + this->Matty.getGlobalBounds().width / 2, this->bar_background.getPosition().y + 25);

	this->George_points_needed.setFont(this->font);
	this->George_points_needed.setCharacterSize(30);
	this->George_points_needed.setString("0");
	this->George_points_needed.setOrigin(this->George_points_needed.getGlobalBounds().width / 2, this->George_points_needed.getGlobalBounds().height / 2);
	this->George_points_needed.setPosition(this->George.getPosition().x + this->George.getGlobalBounds().width / 2, this->bar_background.getPosition().y + 215);

	this->Alex_points_needed.setFont(this->font);
	this->Alex_points_needed.setCharacterSize(30);
	this->Alex_points_needed.setString("7");
	this->Alex_points_needed.setOrigin(this->Alex_points_needed.getGlobalBounds().width / 2, this->Alex_points_needed.getGlobalBounds().height / 2);
	this->Alex_points_needed.setPosition(this->Alex.getPosition().x + this->Alex.getGlobalBounds().width / 2, this->bar_background.getPosition().y + 215);

	this->Matty_points_needed.setFont(this->font);
	this->Matty_points_needed.setCharacterSize(30);
	this->Matty_points_needed.setString("15");
	this->Matty_points_needed.setOrigin(this->Matty_points_needed.getGlobalBounds().width / 2, this->Matty_points_needed.getGlobalBounds().height / 2);
	this->Matty_points_needed.setPosition(this->Matty.getPosition().x + this->Matty.getGlobalBounds().width / 2, this->bar_background.getPosition().y + 215);

	this->doubleAS.setFont(this->font);
	this->doubleAS.setCharacterSize(30);
	this->doubleAS.setFillColor(Color::White);
	this->doubleAS.setString("(S) - Double Attack Speed");
	this->doubleAS.setPosition(100, 1020);

	this->invalidNickText.setFont(this->font);
	this->invalidNickText.setCharacterSize(50);
	this->invalidNickText.setFillColor(Color::White);
	this->invalidNickText.setString("Enter your nickname: ");
	this->invalidNickText.setOrigin(this->invalidNickText.getGlobalBounds().width / 2, 0);
	this->invalidNickText.setPosition(960, 500);
}

void Interface::initHPBar()
{
	this->HealthPoint.setTexture(this->HP_tex);
	for (int i = 0; i < this->HPMax; i++) {
		this->HPBar.push_back(this->HealthPoint);
	}

	for (int i = 0; i < this->HPBar.size(); i++) {
		this->HPBar[i].setPosition((i*60),80);
	}
}

void Interface::initInterface()
{
	this->George.setTexture(George_tex);
	this->Alex.setTexture(Alex_tex);
	this->Matty.setTexture(Matty_tex);
	this->CooldownIcon.setTexture(cooldown_tex);
	this->CooldownIcon.setPosition(50, 220);
	this->bar_background.setTexture(bar_background_tex);
	this->bar_background.setPosition(685,30);
	this->George.setPosition(this->bar_background.getPosition().x+25, this->bar_background.getPosition().y+50);
	this->Alex.setPosition(this->George.getPosition().x + this->George.getGlobalBounds().width+ 25, this->bar_background.getPosition().y + 50);
	this->Matty.setPosition(this->Alex.getPosition().x + this->Alex.getGlobalBounds().width + 25, this->bar_background.getPosition().y + 50);
}

Interface::Interface()
{
	this->initVariables();
	this->initTextures();
	this->initFonts();
	this->initInterface();
	this->initText();
	this->initHPBar();
}

Interface::~Interface()
{
}

void Interface::setCDIcon()
{
	this->CooldownIcon.setTexture(this->cooldown_tex);
}

void Interface::setCDIconRefresh()
{
	this->CooldownIcon.setTexture(this->cooldown_refresh_tex);
}

void Interface::setPointsNull()
{
	this->points = 0;
}

void Interface::setInvalidNickTextOrigin()
{
	this->invalidNickText.setOrigin(this->invalidNickText.getGlobalBounds().width / 2, 0);
}

void Interface::setInvalidNickTextString()
{
	this->invalidNickText.setString("Enter your nickname: ");
}

void Interface::setInvalidNickText_InvalidString(string nick)
{
	this->invalidNickText.setString(nick + " is invalid! Try again!");
}

void Interface::setInvalidNickTextPosition()
{
	this->invalidNickText.setPosition(960, 500);
}

void Interface::setGeorgeExistenceFalse()
{
	this->george_existence = false;
}

void Interface::setAlexExistenceFalse()
{
	this->alex_existence = false;
}

void Interface::setMattyExistenceFalse()
{
	this->matty_existence = false;
}

void Interface::eraseLife()
{
	this->HPBar.erase(this->HPBar.begin() + this->HPBar.size() - 1);
}

void Interface::addPoints(int point)
{
	this->points = this->points + point;
}

int Interface::getHPBarSize()
{
	return this->HPBar.size();
}

int Interface::getPoints()
{
	return this->points;
}

Text Interface::getInvalidNickText()
{
	return this->invalidNickText;
}

bool Interface::getGeorgeExistence()
{
	return this->george_existence;
}

bool Interface::getAlexExistence()
{
	return this->alex_existence;
}

bool Interface::getMattyExistence()
{
	return this->matty_existence;
}



void Interface::update()
{
	if (Mouse::isButtonPressed(Mouse::Left) && this->George.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y))
	{
		george_existence = true;
	}
	if (Mouse::isButtonPressed(Mouse::Left) && this->Alex.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) && this->points >= 7)
	{
		alex_existence = true;
	}
	if (Mouse::isButtonPressed(Mouse::Left) && this->Matty.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) && this->points >= 15)
	{
		matty_existence = true;
	}
	this->points_text.setString("Points: " + to_string(this->points));
}

void Interface::render(RenderTarget& target)
{
	target.draw(this->bar_background);
	target.draw(this->George);
	target.draw(this->Alex);
	target.draw(this->Matty);
	target.draw(this->points_text);
	target.draw(this->George_name);
	target.draw(this->Alex_name);
	target.draw(this->Matty_name);
	target.draw(this->George_points_needed);
	target.draw(this->Alex_points_needed);
	target.draw(this->Matty_points_needed);
	target.draw(this->doubleAS);
	for (int i = 0; i < this->HPBar.size(); i++) {
		target.draw(this->HPBar[i]);
	}
}

void Interface::renderCDIcon(RenderTarget& target)
{
	target.draw(this->CooldownIcon);
}
