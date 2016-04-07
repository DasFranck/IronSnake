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

//Reset text options
void	Menu::resetText()
{
  _text.setColor(sf::Color::White);
  _text.setFont(_font);
  _text.setStyle(sf::Text::Style::Regular);
  _text.setRotation(0);
  _text.setScale(1, 1);
}

//Display Text with string, text size, position vector and two boolean for centered text in x and y.
void	Menu::displayText(std::string const str, short size, sf::Vector2f pos, bool cenx, bool ceny, bool reset)
{
  sf::FloatRect textRect;

  _text.setString(str);
  _text.setCharacterSize(size);
  textRect = _text.getLocalBounds();
  _text.setOrigin(textRect.left + (cenx ? textRect.width/2.0f : 0), textRect.top + (ceny ? textRect.height/2.0f : 0));
  _text.setPosition(pos);
  _ironSnake->_win.draw(_text);
  if (reset)
    this->resetText();
}

//Display the menu on screen
void	Menu::display()
{
  //Clear Window
  _ironSnake->_win.clear(sf::Color::Black);

  //Display Main Menu text
  if (_choice <= MAIN_MENU_END)
  {
    //TITLE
    _text.setColor(sf::Color(0x75, 0x35, 0x00));
    this->displayText("IRON SNAKE", 110, sf::Vector2f(WH_SIZE/2.0f, WV_SIZE/7.5f), true, true);

    //CHOICES
    this->displayText("Play",     (_choice == MAIN_MENU_BEGIN ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 4), false, true);
    this->displayText("Options",  (_choice == MAIN_MENU_BEGIN + 1 ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 5.5), false, true);
    this->displayText("Exit",     (_choice == MAIN_MENU_BEGIN + 2 ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 7), false, true);
  }
  //Display Option Menu text
  else if (_choice <= OPTIONS_MENU_END)
  {
    //SUBMENU NAME
    this->displayText("OPTIONS", 90, sf::Vector2f(WH_SIZE/2.0f, WV_SIZE/7.5f), true, true);

    //CHOICES
    this->displayText("Choice 1", (_choice == OPTIONS_MENU_BEGIN ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 4), false, true);
    this->displayText("Choice 2", (_choice == OPTIONS_MENU_BEGIN + 1 ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 5), false, true);
    this->displayText("Choice 3", (_choice == OPTIONS_MENU_BEGIN + 2 ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 6), false, true);
    this->displayText("Return to main menu", (_choice == OPTIONS_MENU_BEGIN + 3 ? 60 : 40), sf::Vector2f(WH_SIZE/8, WV_SIZE/10 * 7), false, true);
  }

  //Put all on screen
  _ironSnake->_win.display();
}

//Manage key input
void	Menu::manageKey()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    if (_choice <= MAIN_MENU_END)
      _choice = (_choice == MAIN_MENU_END ? MAIN_MENU_BEGIN : _choice + 1);
    else if (_choice <= OPTIONS_MENU_END)
      _choice = (_choice == OPTIONS_MENU_END ? OPTIONS_MENU_BEGIN : _choice + 1);
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    if (_choice <= MAIN_MENU_END)
      _choice = (_choice == MAIN_MENU_BEGIN ? MAIN_MENU_END : _choice - 1);
    else if (_choice <= OPTIONS_MENU_END)
      _choice = (_choice == OPTIONS_MENU_BEGIN ? OPTIONS_MENU_END : _choice - 1);
  }

  //Return Key -- Execute selected action
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    switch (_choice)
    {
      //MainMenu -- Play
      case MAIN_MENU_BEGIN:
        _ironSnake->start();
        break;

      //MainMenu -- Options
      case MAIN_MENU_BEGIN + 1:
        _choice = OPTIONS_MENU_BEGIN;
        break;

      //MainMenu -- Exit
      case MAIN_MENU_BEGIN + 2:
        exit(0);
        break;

      case OPTIONS_MENU_BEGIN:
      case OPTIONS_MENU_BEGIN + 1:
      case OPTIONS_MENU_BEGIN + 2:
        break;

      //OptionMenu -- Return to main menu
      case OPTIONS_MENU_BEGIN + 3:
        _choice = MAIN_MENU_BEGIN + 1;
    }
}
