#pragma once

//Include libs
#include <SFML/Graphics.hpp>

//Graphics define
# define FRAMES_PER_SECOND 60
# define WH_SIZE           1280
# define WV_SIZE           720

class IronSnake
{
  public:
    sf::RenderWindow	_win;
    sf::Font		_font;
    sf::Text		_text;
    bool		_focus;

  public:
    IronSnake();
    ~IronSnake();
    void		display();
    void		manageKey();
};
