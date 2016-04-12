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
  _sprites["normal"][0].setPosition(_posX, _posY);

  if (_dir == Direction::LEFT)
    _sprites["normal"][0].scale(-1, 1);
  return (_sprites["normal"][0]);
}

void		Character::walk(Direction _dir)
{
  if (_dir == Direction::RIGHT)
  {
    printf("RIGHT\n");
    _posX += 10 * _spd;
  }
  else if (_dir == Direction::LEFT)
  {
    printf("LEFT\n");
    _posX -= 10 * _spd;
  }
}
