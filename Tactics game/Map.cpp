#include "Map.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Map::Map(char* config_path, Player* player_a, Player* player_b)
{
  std::string filename {config_path};
  std::ifstream file{filename};
  std::string line;
  std::getline(file, line);
  std::getline(file, line, '_');
  std::stringstream ss(line);
  ss>>columns_;
  std::getline(file, line);
  std::stringstream ss2(line);
  ss2>>rows_;
  while(std::getline(file, line))
  {
    std::vector<Field*> row;
    for (auto &c : line)
    {
      switch (c)
      {
        case 'a':
        {
          Field* field = new Field(player_a, 1, false);
          row.push_back(field);
          break;
        }
        case 'b':
        {
          Field* field = new Field(player_b, 1, false);
          row.push_back(field);
          break;
        }
        case '-':
        {
          Field* field = new Field(nullptr, 0, true);
          row.push_back(field);
          break;
        }
        case '0':
        {
          Field* field = new Field(nullptr, 0, false);
          row.push_back(field);
          break;
        }
      }
    }
    fields_.push_back(row);
  }
  file.close();
}
int Map::getColumns() const
{
  return columns_;
}
int Map::getRows() const
{
  return rows_;
}
void Map::setActive()
{
  if (output_active_==true)
  {
    output_active_=false;
  }
  else output_active_=true;
}
int Map::getNumFields(Player* actpl)
{
  int numfields=0;
  for(std::vector<Field*>& row : fields_)
  {
    for(auto& c : row)
    {
      if (actpl==c->getPlayer())
      numfields+=1;
    }
  }
  return numfields;
}
std::vector<std::vector<Field*>> Map::getFields()
{
  return fields_;
}
void Map::printMap()
{
  if (output_active_==true)
  {
    std::cout<<"  ";
    for (int i=1; i<(columns_+1); ++i)
    {
      std::cout<<"| "<<i<<" ";
    }
    std::cout<<std::endl;
    int rows=0;
    for (auto& row : fields_)
    {
      rows+=1;
      std::cout<<rows<<" ";
      for (auto& c : row)
      {
        if (c->getPlayer()!=nullptr)
        {
          std::cout<<"|"<<c->getPlayer()->getID()<<" "<<c->getChips();
        }
          else if ((c->getWater())==true)
          {
            std::cout<<"| ~ ";
          }
            else if(c->getPlayer()==nullptr && c->getChips()==0) {std::cout<<"|   ";}
      }
      std::cout<<std::endl;
    }
    std::cout<<std::endl;
  }
}
void Map::setPlayerChips(Player* pl)
{
  int sumchips=0;
  for (auto& row : fields_)
  {
    for (auto field : row)
    {
      if (pl==field->getPlayer())
      {
        sumchips+=field->getChips();
      }
    }
  }
  if (sumchips%3!=0)
  {
    sumchips=(sumchips/3)+1;
    sumchips+=(pl->getChips());
    pl->setChips(sumchips);
  }
    else {
      sumchips=(sumchips/3);
      sumchips+=(pl->getChips());
      pl->setChips(sumchips);
    }
}
bool Map::getMapst() const
{
  return output_active_;
}
Map::~Map() {
    for (auto& row : fields_) {
        for (auto& fieldPoint : row) {
            delete fieldPoint;
        }
        row.clear();
    }
    fields_.clear();
}