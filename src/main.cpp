#include <iostream>
#include <SFML/Graphics.hpp>
#include "IronSnake.hpp"
#include "Menu.hpp"

int			main()
{
  sf::Clock		clock;
  sf::Time		LastFrame;
  sf::Time		TimePlayed;
  IronSnake		ironSnake;
  Menu			menu(&ironSnake);

  //Main Loop
  while (ironSnake._win.isOpen())
  {
    sf::Event event;

    TimePlayed = clock.getElapsedTime();

    //Event Manager
    while (ironSnake._win.pollEvent(event))
    {
      switch (event.type)
      {
        case sf::Event::Closed:
          ironSnake._win.close();
          break;

        case sf::Event::Resized:
          std::cout << "New Size : " << event.size.width << "*" << event.size.height << std::endl;
          break;

        case sf::Event::KeyPressed:
          ironSnake._focus ? ironSnake.manageKey() : menu.manageKey();
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            return (0);
          break;
      }
    }

    //Display
    ironSnake._focus ? ironSnake.display() : menu.display();

    //Game capped at [FRAMES_PER_SECOND] FPS (IronSnake.hpp)
    sf::sleep(sf::milliseconds((1000 / FRAMES_PER_SECOND) - TimePlayed.asMilliseconds() - LastFrame.asMilliseconds()));
  }
}
