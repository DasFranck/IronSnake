#include "IronSnake.hpp"

IronSnake::IronSnake()
{
  _focus = false;
  _win.create(sf::VideoMode(WH_SIZE, WV_SIZE), "Iron Snake");
  //_win.setVerticalSyncEnabled(true);

  if (!_font.loadFromFile("ressources/fonts/arial.ttf"))
    exit(1);

  _text.setFont(_font);
  _text.setCharacterSize(24);
}

IronSnake::~IronSnake()
{

}

void	IronSnake::display()
{

}

void	IronSnake::manageKey()
{

}
