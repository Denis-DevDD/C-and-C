#include "Field.hpp"

#include <iostream>

Field::~Field()=default;
int Field::getChips() const
{
  return chips_;
}
Player* Field::getPlayer()
{
  return player_;
}
bool Field::getWater() const
{
  return is_water_;
}
void Field::setChips(int c)
{
  chips_=c;
}
void Field::setPlayer(Player* player)
{
  player_=player;
}
