#include "Textbox.h"


void Textbox::setTextbox(int size, Color color, bool selected, Font& font, Vector2f position)
{
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	textbox.setFont(font);
	textbox.setPosition(position);
	isSelected = selected;

	this->board.setFillColor(Color::White);
	this->board.setSize({ 200.f,5.f });
	this->board.setPosition(860,650);

	if (selected)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}

void Textbox::setLimit(bool hasLim, int lim)
{
	hasLimit = hasLim;
	limit = lim;
}

void Textbox::setIsSelected(bool selected)
{
	isSelected = selected;
	if (!selected)
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

void Textbox::draw(RenderTarget& target)
{
	target.draw(this->board);
	target.draw(textbox);
}

void Textbox::inputCharacter(int charTyped, string& nick)
{

	if (!Keyboard::isKeyPressed(Keyboard::BackSpace) &&
		!Keyboard::isKeyPressed(Keyboard::Tab) &&
		!Keyboard::isKeyPressed(Keyboard::Escape))
	{
		text << static_cast<char>(charTyped);
	}
	else if (Keyboard::isKeyPressed(Keyboard::BackSpace))
	{
		if (text.str().length() > 0)
		{
			deleteCharacter();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Tab))
	{

		if (text.str().length() > 0)
		{
			nick = text.str();
			text.str("");
		}
	}
	textbox.setString(text.str() + "_");
}

void Textbox::deleteCharacter()
{
	string t = text.str();
	string newT = "";

	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}

void Textbox::update(sf::Event ev, string& nick)
{
	if (isSelected)
	{
		int charTyped = ev.text.unicode;
		if (charTyped < 128)
		{
			if (hasLimit)
			{
				if (text.str().length() <= limit)
				{
					inputCharacter(charTyped, nick);
				}
				else if (text.str().length() > limit && Keyboard::isKeyPressed(Keyboard::BackSpace))
				{
					deleteCharacter();
				}
			}
			else
			{
				inputCharacter(charTyped, nick);
			}
		}
	}
}