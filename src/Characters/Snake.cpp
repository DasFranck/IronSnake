#include "Snake.hpp"

//HP = 100, SPD = 1
Snake::Snake() : Character(100, 1)
{
  //POS To be set
  //_posX = 0;
  //_posY = 0;

  //SIZE To be set
}

Snake::~Snake()
{
}

void	Snake::loadSprites()
{
}

void	Snake::loadRessources()
{
  this->loadSprites();
}
