#include "Character.hpp"

Character::Character(int hp, float spd)
{
  _hp = hp;
  _spd = spd;
  _dir = RIGHT;
}

void	Character::loadSprite(std::string keym, int keyv, std::string path)
{
  sf::Texture	*texture;
  sf::Sprite	sprite;


  if (!(texture = new sf::Texture) || !texture->loadFromFile(path))
    exit(1);

  sprite.setTexture(*texture);
  _sprites[keym].push_back(sprite);
}

sf::Sprite&	Character::getSprite()
{
  //DEFAULT ANIMATION
  _sprites["normal"][0].setPosition(0, 0);
  return (_sprites["normal"][0]);
}
