#pragma once

# include <iostream>
# include <string>
# include <SFML/Graphics.hpp>

class Character
{
  enum Direction {LEFT, RIGHT};

  public:
    //Position on screen
    int		_posX;
    int		_posY;

    //Size of the sprite (not actually an Hitbox)
    int		_sizeX;
    int		_sizeY;

    //Health Points
    int		_hp;
    //Speed
    int		_spd;

    //MAP OF VECTOR OF SPRITES.
    std::map<std::string, std::vector<sf::Sprite>>	_sprites;

    //MAP OF NOISES (Type Unknown for now)
    //std::map< /* NOISES */ >

    //Direction of the character
    Direction	_dir;

    //VECTOR OF IWeapons*
    //std::vector<IWeapon *>	_weapons;

  protected:
    Character(int hp, float spd);

  public:
    virtual ~Character() {}

  public:
    void		loadSprite(std::string keym, int keyv, std::string path);
    virtual void	loadSprites() = 0;
    virtual void	loadRessources() = 0;

    void		display();
};
