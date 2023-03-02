#include "Ranking.h"
#include <string>


void Ranking::initFont()
{
    if (!font.loadFromFile("Fonts/Badaboom.ttf")) {
        cout << "Error loading font" << endl;
    }
}

void Ranking::initText()
{
    this->rankingText.setFont(this->font);
    this->rankingText.setFillColor(Color::White);
    this->rankingText.setCharacterSize(70);
    this->rankingText.setString("Ranking");
    this->rankingText.setPosition(900, 200);

    this->escapeText.setFont(this->font);
    this->escapeText.setCharacterSize(30);
    this->escapeText.setFillColor(Color::White);
    this->escapeText.setString("(ESC) - Back To Main Menu");
    this->escapeText.setPosition(100, 1000);

    this->saveText.setFont(this->font);
    this->saveText.setCharacterSize(30);
    this->saveText.setFillColor(Color::White);
    this->saveText.setString("(Tab) - Save");
    this->saveText.setPosition(100, 1000);

    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(300);
    this->gameOverText.setFillColor(Color::White);
    this->gameOverText.setString("GAME OVER!");
    this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().width / 2, 0);
    this->gameOverText.setPosition(960, 100);
}

void Ranking::initTexture()
{
    this->background_tex.loadFromFile("Textures/Game_Background.jpg");
}

void Ranking::initSprite()
{
    this->background.setTexture(background_tex);
}

void Ranking::initTextbox()
{
    this->textbox.setTextbox(30,Color::White,true,this->font,{860,600});
}

void Ranking::initScoreboard(string text, Vector2f pos)
{
    this->listScoreboard.setFont(this->font);
    this->listScoreboard.setCharacterSize(30);
    this->listScoreboard.setFillColor(Color::White);
    this->listScoreboard.setString(text);
    this->listScoreboard.setPosition(pos);
}


Ranking::Ranking()
{
    this->initFont();
    this->initText();
    this->initTextbox();
    this->initTexture();
    this->initSprite();
}

Ranking::~Ranking()
{
}

//REGEX
bool Ranking::correctNick(string nick)
{
    std::regex correct("^([A-Z a-z 0-9]){1,10}$");
    if (std::regex_match(nick, correct))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//FILESYSTEM
void Ranking::loadRanking()
{
    this->rankingVector.clear();
    filesystem::path filePath("Ranking/records.txt");
    if (filesystem::exists(filePath))
    {
        ifstream read(filePath);
        if (read) {
            string nick;
            int points;
            while (read >> nick && read >> points) {
                this->rankingVector.push_back({ points, nick });
            }
        }
    }
    else
    {
        ofstream open(filePath);
    }
}

int Ranking::rankingVectorSize()
{
    if (this->rankingVector.size() < 10) {
        return this->rankingVector.size();
    }
    else {
        return 10;
    }
}

//RANGES
void Ranking::showRanking(RenderTarget& target)
{
    int number = 1;
    float positionX = 900, positionY = 300;
    ranges::sort(this->rankingVector, ranges::greater{});

    for (int i = 0; i < rankingVectorSize(); i++) {
        stringstream ss;
        pair<int, string> p = this->rankingVector[i];
        ss << number << ". " << p.second << " " << p.first;
        this->initScoreboard(ss.str(),{positionX,positionY});
        target.draw(this->listScoreboard);
        number++;
        positionY += 40;
    }
}

void Ranking::saveToFile(string nick, int score)
{
    filesystem::path filePath("Ranking/records.txt");
    if (filesystem::exists(filePath))
    {
        std::ofstream myfile(filePath, ios::app);
        if (myfile)
        {
            myfile << nick << " " << score << endl;
        }
        else
        {
            cout << "Plik jest zly" << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "Error path nie istnieje" << endl;
    }
}

void Ranking::update()
{

}

void Ranking::updateTextbox(Event ev, string& nick)
{
    this->textbox.update(ev, nick);
}

void Ranking::render(RenderTarget& target)
{
    target.draw(this->background);
    target.draw(this->rankingText);
    target.draw(this->escapeText);
}

void Ranking::renderTextbox(RenderTarget& target)
{
    target.draw(this->background);
    target.draw(this->gameOverText);
    this->textbox.draw(target);
    target.draw(this->saveText);
}
