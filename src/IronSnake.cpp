#include "IronSnake.hpp"

IronSnake::IronSnake()
{
  _focus = false;
  _win.create(sf::VideoMode(WH_SIZE, WV_SIZE), "Iron Snake");
  //_win.setVerticalSyncEnabled(true);
  this->loadFonts();
  _text.setFont(_font["arial"]);
  _text.setCharacterSize(24);
}

IronSnake::~IronSnake()
{

}

void	IronSnake::loadFont(std::string key, std::string path)
{
  sf::Font	font;

  if (!font.loadFromFile(path))
    exit(1);
  _font[key] = font;
}

//Font loader (Loaded at the beginning)
void	IronSnake::loadFonts()
{
  this->loadFont("arial", "ressources/fonts/arial.ttf");
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
  this->loadRessources();
}
