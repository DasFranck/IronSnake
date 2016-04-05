#include "Menu.hpp"

Menu::Menu(IronSnake *iS) : _ironSnake(iS)
{
  _choice = 1;
  if (!_font.loadFromFile("ressources/fonts/arial.ttf"))
    exit(1);

  _text.setFont(_font);
}


Menu::~Menu()
{}

void	Menu::displayText(std::string const str, short size, bool centered, sf::Vector2f pos)
{
  sf::FloatRect textRect;

  _text.setString(str);
  _text.setCharacterSize(size);
  textRect = _text.getLocalBounds();
  if (centered)
    _text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
  _text.setPosition(pos);
  _ironSnake->_win.draw(_text);
}

void	Menu::display()
{
  //Clear Window
  _ironSnake->_win.clear(sf::Color::Black);

  //Display Main Menu text
  this->displayText("IRON SNAKE", 110, true, sf::Vector2f(WH_SIZE/2.0f, WV_SIZE/7.5f));
  this->displayText("Play", (_choice == 1 ? 65 : 40), true, sf::Vector2f(WH_SIZE/2.7f, WV_SIZE/10 * 4));
  this->displayText("Options", (_choice == 2 ? 65 : 40), true, sf::Vector2f(WH_SIZE/2.7f, WV_SIZE/10 * 5.5));
  this->displayText("Exit", (_choice == 3 ? 65 : 40), true, sf::Vector2f(WH_SIZE/2.7f, WV_SIZE/10 * 7));

  //Put all on screen
  _ironSnake->_win.display();
}

//Max menu size is 3
#define MENU_SIZE 3

void	Menu::manageKey()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    _choice = (_choice == MENU_SIZE ? 1 : _choice + 1);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    _choice = (_choice == 1 ? MENU_SIZE : _choice - 1);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    switch (_choice)
    {
      //Play
      case 1:
        break;

      //Options
      case 2:
        break;

      //Exit
      case 3:
        exit(0);
    }
}
