#pragma once

# include "IronSnake.hpp"

#define MAIN_MENU_BEGIN		1
#define MAIN_MENU_SIZE		3
#define MAIN_MENU_END		MAIN_MENU_BEGIN + MAIN_MENU_SIZE -1

#define OPTIONS_MENU_BEGIN	MAIN_MENU_END + 1
#define OPTIONS_MENU_SIZE	4
#define OPTIONS_MENU_END	OPTIONS_MENU_BEGIN + OPTIONS_MENU_SIZE -1

class Menu
{
  //Pointer on IronSnake instance
  IronSnake		*_iS;
  sf::Text		_text;
  uint8_t		_choice;

  public:
    Menu(IronSnake *iS);
    ~Menu();

    //Display functions
    void		display();
    void		resetText();
    void		displayText(std::string const str, short size, sf::Vector2f pos, bool cenx = false, bool ceny = false, bool reset = true);

    //Input Manager function
    void		manageKey();
};
