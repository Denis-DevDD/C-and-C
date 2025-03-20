#ifndef FIELD_HPP
#define FIELD_HPP

#include "Player.hpp"

class Field
{
  private:
    Player* player_;
    int chips_;
    bool is_water_;
  public:
    Field(Player* player, int chips, bool is_water) :
      player_{player}, chips_{chips}, is_water_{is_water} {}
    ~Field();
    int getChips() const;
    void setPlayer(Player* player);
    Player* getPlayer();
    bool getWater() const;
    void setChips(int c);
};

#endif