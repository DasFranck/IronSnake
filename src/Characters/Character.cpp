#include "Character.hpp"

Character::Character(int hp, float spd)
{
  _hp = hp;
  _spd = spd;
  _dir = RIGHT;
}

void	Character::loadSprite(std::string keym, int keyv, std::string path)
{
  sf::Texture	texture;
  sf::Sprite	sprite;

  if (!texture.loadFromFile(path))
  {
    std::cerr << "Failure to load: " << path << "\nExiting..." << std::endl;
    //Load Failed
    exit(1);
  }
  sprite.setTexture(texture);
  _sprites[keym][keyv] = sprite;
}

void	Character::display()
{
}
