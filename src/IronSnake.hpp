#pragma once

//Include libs
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

//Include Headers
#include "Characters/ICharacter.hpp"

//Graphics define
# define FRAMES_PER_SECOND 60
# define WH_SIZE           1280
# define WV_SIZE           720

class IronSnake
{
  public:
    //InstaLoaded
    sf::RenderWindow			_win;
    std::map<std::string, sf::Font>	_font;
    bool				_focus;

    sf::Text				_text;

    //PTR ON CHARACTER
    ICharacter				*_player;

    //VECTOR OF IMapObject*
    //std::vector<IMapObject *>		_mapobjs;

    //VECTOR OF IEnemy*
    //std::vector<IEnemy *>		_enemies;

    //VECTOR OF IProjectile*
    //std::vector<IProjectile *>		_projectiles;

  public:
    IronSnake();
    ~IronSnake();
    void		display();
    void		loadFont(std::string key, std::string path);
    void		loadFonts();
    void		loadRessources();
    void		manageKey();
    void		start();
    void		stop();
};
