#include "Game.h"

//Initialization
void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(1920, 1080), "Game!", Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
    this->Frames = 1;
    this->enemySpawnTimerMax = 150;
    this->enemySpawnTimer = 0;
    this->abilityCastThread = true;
    this->gameState = 0;
    this->menuState = 1;
    this->rankingState = 0;
}

//Constructors/Destructors
Game::Game()
{
    this->initWindow();
    this->initVariables();
}

Game::~Game()
{
	delete this->window;
    
    for (auto* i : this->enemies) {
        delete i;
    }
}


//Functions

//THREAD
void Game::abilityDuration(bool& threadFree)
{
    this->interface.setCDIconRefresh();
    this->george.shootCooldownMax = this->george.shootCooldownMax / 2;
    this->alex.shootCooldownMax = this->alex.shootCooldownMax / 2;
    this->matty.shootCooldownMax = this->matty.shootCooldownMax / 2;
    this_thread::sleep_for(chrono::seconds(5));
    this->george.shootCooldownMax = this->george.shootCooldownMax * 2;
    this->alex.shootCooldownMax = this->alex.shootCooldownMax * 2;
    this->matty.shootCooldownMax = this->matty.shootCooldownMax * 2;
    this_thread::sleep_for(chrono::seconds(5));
    this->interface.setCDIcon();
    this->abilityCastThread = true;

}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed) {
            this->window->close();
        }

        //Game on
        if (this->gameState == 1) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
               this->window->close();
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                if (this->abilityCastThread) {
                    this->abilityCastThread = false;
                    thread abilityCast(&Game::abilityDuration, this, ref(this->abilityCastThread));
                    abilityCast.detach();
                }
            }
        }

        //Ranking
        if (this->rankingState == 1) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                this->menuState = 1;
                this->rankingState = 0;
            }
        }

        //Game over
        if (this->gameState == 2) {
            if (this->sfEvent.type == Event::TextEntered) {
                this->ranking.updateTextbox(this->sfEvent, this->nick);
            }
        }

        //Menu updating
        if (this->menuState == 1) {
            switch (this->sfEvent.type) {
            case Event::KeyReleased:
                switch (sfEvent.key.code) {
                case Keyboard::Up:
                    this->menu.moveUp();
                    break;

                case Keyboard::Down:
                    this->menu.moveDown();
                    break;

                case Keyboard::Enter:
                    switch (menu.getPressedItem()) {
                    case 0:
                        cout << "Play button selected" << endl;
                        this->gameState = 1;
                        this->menuState = 0;
                        break;
                    case 1:
                        cout << "Ranking button selected" << endl;
                        this->rankingState = 1;
                        this->menuState = 0;
                        break;
                    case 2:
                        this->window->close();
                        break;
                    }
                }
                break;
            }
        }
    }
}

void Game::updateInterface()
{
    this->interface.update();
}

void Game::updateGeorge()
{
    if (this->interface.getGeorgeExistence() == true) {
        this->george.update();
        if (!this->alex.AlexPicked() && !this->matty.MattyPicked()) {
            this->george.updatePosition();
        }
    }
}

void Game::updateAlex()
{
    if (this->interface.getAlexExistence() == true) {
        this->alex.update();
        if (!this->george.getGeorgePicked() && !this->matty.MattyPicked()) {
            this->alex.updatePosition();
        }
    }
}

void Game::updateMatty()
{
    if (this->interface.getMattyExistence() == true) {
        this->matty.update();
        if (!this->george.getGeorgePicked() && !this->alex.AlexPicked()) {
            this->matty.updatePosition();
        }
    }
}

float Game::countFrames()
{
    if (this->Frames < 5000) {
        return 5000;
    }
    else {
        return this->Frames;
    }
}

void Game::updateEnemies()
{   
    this->enemySpawnTimer++;
    if (this->enemySpawnTimer >= this->enemySpawnTimerMax/(this->countFrames() / 5000)) {
        this->enemies.push_back(new Enemy());
        this->enemySpawnTimer = 0;
    }

    for (int i = 0; i < enemies.size();i++) {

        bool enemy_removed = false;
        this->enemies[i]->update();

        //Killing enemies by heroes
        for (size_t j = 0; j < this->george.bullets.size() && !enemy_removed; j++) {
            if (this->george.bullets[j].getGlobalBounds().intersects(this->enemies[i]->shape.getGlobalBounds())) {
                
                this->george.bullets.erase(this->george.bullets.begin() + j);                   //Bullet destroyed
                this->enemies[i]->setHP(this->george.attackDamage);
                if (this->enemies[i]->getHP() <= 0) {
                    this->interface.addPoints(this->enemies[i]->getHPMax());                         //Points added
                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin() + i);                             //Enemy destroyed
                    enemy_removed = true;                             
                }
            }
        }

        for (size_t j = 0; j < this->alex.bullets.size() && !enemy_removed; j++) {
            if (this->alex.bullets[j].getGlobalBounds().intersects(this->enemies[i]->shape.getGlobalBounds())) {

                this->alex.bullets.erase(this->alex.bullets.begin() + j);                       //Bullet destroyed
                this->enemies[i]->setHP(this->alex.attackDamage);
                if (this->enemies[i]->getHP() <= 0) {
                    this->interface.addPoints(this->enemies[i]->getHPMax());                         //Points added
                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin() + i);                             //Enemy destroyed
                    enemy_removed = true;
                }
            }
        }

        for (size_t j = 0; j < this->matty.bullets.size() && !enemy_removed; j++) {
            if (this->matty.bullets[j].getGlobalBounds().intersects(this->enemies[i]->shape.getGlobalBounds())) {

                this->matty.bullets.erase(this->matty.bullets.begin() + j);                     //Bullet destroyed
                this->enemies[i]->setHP(this->matty.attackDamage);
                if (this->enemies[i]->getHP() <= 0) {
                    this->interface.addPoints(this->enemies[i]->getHPMax());                         //Points added
                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin() + i);                             //Enemy destroyed
                    enemy_removed = true;
                }
            }
        }

        //Damaging spawn
        if (!enemy_removed) {
            if (this->enemies[i]->shape.getGlobalBounds().left <= 400) {
                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);
                this->interface.eraseLife();
                if (this->interface.getHPBarSize() == 0) {
                    this->gameOver();
                }
            }
        }
    }
}

void Game::deleteEnemies()
{
    for (auto* i : this->enemies) {
        delete i;
    }
    this->enemies.clear();
}

void Game::deleteBullets()
{
    this->george.eraseBullets();
    this->alex.eraseBullets();
    this->matty.eraseBullets();
}

void Game::update()
{
    this->updateSFMLEvents();  

    if (this->gameState == 1) {
        this->updateInterface();
        this->updateGeorge();
        this->updateAlex();
        this->updateMatty();
        if (this->interface.getGeorgeExistence() == true) {
            this->updateEnemies();
            this->Frames++;
            cout << Frames << endl;
        }
    }
}

void Game::render()
{
    this->window->clear();

    //Render
    if (this->menuState == 1) {
        this->menu.render(*window);
    }
        
    if (this->rankingState == 1) {
        this->ranking.render(*window);
        this->ranking.loadRanking();
        this->ranking.showRanking(*window);

    }

    if (this->gameState == 1) {
        this->map.render(*this->window);
        this->interface.render(*this->window);
        if (this->interface.getGeorgeExistence() == true) {
            this->george.render(*this->window);
            this->interface.renderCDIcon(*this->window);
        }

        if (this->interface.getAlexExistence() == true) {
            this->alex.render(*this->window);
        }

        if (this->interface.getMattyExistence() == true) {
            this->matty.render(*this->window);
        }

        for (int i = 0; i < this->enemies.size(); i++) {
            this->enemies[i]->render(*this->window);
        }
    }

    if (this->gameState == 2) {
        this->ranking.renderTextbox(*window);
        this->renderGameOver();
    }

    this->window->display();
}

void Game::gameOver()
{
    this->gameState = 2;
    this->menuState = 0;
    this->rankingState = 0;
}

void Game::renderGameOver()
{
    this->interface.setInvalidNickTextOrigin();
    this->window->draw(this->interface.getInvalidNickText());
    if (this->nick != "") {
        if (this->ranking.correctNick(nick)) {
            this->ranking.saveToFile(nick, this->interface.getPoints());
            this->restartGame();
            this->interface.setInvalidNickTextString();
        }
        else {
            this->interface.setInvalidNickText_InvalidString(nick);
            this->interface.setInvalidNickTextOrigin();
            this->interface.setInvalidNickTextPosition();
        }
        this->nick = "";
    }
}

void Game::restartGame()
{
    this->interface.setGeorgeExistenceFalse();
    this->interface.setAlexExistenceFalse();
    this->interface.setMattyExistenceFalse();
    this->deleteEnemies();
    this->deleteBullets();
    this->interface.initHPBar();
    this->interface.setPointsNull();
    this->menuState = 1;
    this->gameState = 0;
    this->rankingState = 0;
    this->Frames = 1;
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
