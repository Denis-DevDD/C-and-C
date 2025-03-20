#include "PositionCommand.hpp"
#include <iostream>
#include "Exceptions.hpp"
#include <algorithm>
bool PositionCommand::execute(Game* game)
{
  //==============checking the parameters===
  std::vector<std::string> input = game->getParser()->getUserInput();
  if (input.size() != 1)
  {
    throw CommandExceptions("E_INVALID_PARAM_COUNT");
  }
  //==============needed variables=======
  Room* current_room = game->getCurrentRoom();
  std::vector<Enemy*> enemies = current_room->getEnemies();
  std::sort(enemies.begin(), enemies.end(), Functions::compareEnemies);
  std::vector<Player*> players = game->getPlayers();

  //==============printin players=======
  for (auto& player : players)
  {

    if (player->getIfDead())
    {
      Field* field_of_plr = current_room->getNeededRoom(player->getId());
      int y = field_of_plr->getY()+1;
      int x = field_of_plr->getX()+1;
      std::cout<<player->getClassName()<<" ["<<player->getId()<<"] \""
      <<player->getName()<<"\" on ("<<y<<","<<x<<")"<<std::endl;
    }
  }
  //==============printing enemies=======
  for (auto& enemy : enemies)
  {
    if (enemy->getIfDead())
    {
      Field* field_of_plr = current_room->getNeededEnemy(enemy);
      int y = field_of_plr->getY()+1;
      int x = field_of_plr->getX()+1;
      std::cout<<enemy->getName()<<" "<<enemy->getNumber()
      <<" ["<<enemy->getId()<<enemy->getNumber()<<"] "
      <<"on ("<<y<<","<<x<<")"<<std::endl;
    }
  }

  return true;
}
