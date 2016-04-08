#pragma once

class ICharacter
{
  public:
    int		_posX;
    int		_posY;
    int		_hp;

    //MAP OF SPRITES (Type Unknown for now).
    //std::map<std::vector< /* SPRITES */ >>

    //DIRECTION (Maybe Enum LEFT/RIGHT).

    //VECTOR OF IWeapons*
    //std::vector<IWeapon *>	_weapons;

  public:
    ICharacter();
    virtual ~ICharacter();
};
