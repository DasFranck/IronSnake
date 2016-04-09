#include "Snake.hpp"

//HP = 100, SPD = 1
Snake::Snake() : Character(100, 1)
{
  //POS To be set
  //_posX = 0;
  //_posY = 0;

  //SIZE To be set
  this->loadRessources();
}

Snake::~Snake()
{
}

void	Snake::loadSprites()
{
  _sprites["normal"] = *new std::vector<sf::Sprite>;
  this->loadSprite("normal", 0, "./ressources/sprites/Snake/normal_0.png");
}

void	Snake::loadRessources()
{
  this->loadSprites();
}
