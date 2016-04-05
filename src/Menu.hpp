#pragma once

# include "IronSnake.hpp"

class Menu
{
  //Pointer on IronSnake instance
  IronSnake		*_ironSnake;
  sf::Font		_font;
  sf::Text		_text;
  uint8_t		_choice;

  public:
    Menu(IronSnake *iS);
    ~Menu();
    void		display();
    void		displayText(std::string const str, short size, bool centered, sf::Vector2f pos);
    void		manageKey();
};
