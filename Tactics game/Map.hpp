#ifndef MAP_HPP
#define MAP_HPP

#include "Field.hpp"
#include "Player.hpp"
#include <vector>

class Map
{
  private:
    int columns_;
    int rows_;
    std::vector<std::vector<Field*>> fields_;
    bool output_active_=true;

  public:
    Map(char* config_path, Player* player_a, Player* player_b);
    void setPlayerChips(Player* pl);
    std::vector<std::vector<Field*>> getFields();
    void setActive();
    int getNumFields(Player* actpl);
    void printMap();
    int getColumns() const;
    int getRows() const;
    bool getMapst() const;
    ~Map();
};

#endif

