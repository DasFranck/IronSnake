#pragma once

# include "Character.hpp"

class Snake : public Character
{
  public:
    Snake();
    ~Snake();

    void	loadRessources();
    void	loadSprites();
};
