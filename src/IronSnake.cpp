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

//Ressource loader
void	IronSnake::loadRessources()
{

}

//Display the game on screen
void	IronSnake::display()
{

}

//Manage key input
void	IronSnake::manageKey()
{

}

//Stop the game and go back to the main menu
void	IronSnake::stop()
{
  _focus = false;
}

//Start the game
void	IronSnake::start()
{
  _focus = true;
  printf("GAME STARTED");
  this->loadRessources();

}
