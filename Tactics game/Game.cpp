#include "Game.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

Game::Game(int maximum_rounds, char* config_path)
{
  max_rounds_=maximum_rounds;
  player_a_=new Player('A');
  player_b_=new Player('B');
  active_player_=nullptr;
  map_ = new Map(config_path, player_a_, player_b_);
}
void Game::start()
{
  std::cout<<"Welcome to OOPtimal Tactics!\n";
  std::cout << "Playing maximum of " << max_rounds_ << " round(s)!\n";
}
int Game::getRoundNumber(char* string)
{
  int a=std::stoi(string);
  return a;
}
bool Game::isValidRoundNumber(int rounds)
{
  if (rounds>=1)
  {
    return true;
  }
  else return false;
}
bool Game::isValidConfig(char* config_path)
{
  std::string filename {config_path};
  std::ifstream file{filename};
  if (!file.is_open())
  {
    return false;
  }
  std::string line;
  std::getline(file, line);
  if (line != "OOP")
  {
    return false;
  } else return true;
}
bool Game::isRunning()
{
  if ((current_round_<=max_rounds_) || (map_->getNumFields(player_a_)!=0) || (map_->getNumFields(player_b_)!=0))
  {
    if (phase_==Phase::PLACEMENT)
    {
      if (active_player_==nullptr)
      {
        std::cout<<"\n------------------\nRound "<<current_round_<<"/"<<max_rounds_<<" starts!\n------------------\n\n";
        std::cout<<"------------------\nPlacement Phase\n------------------\n";
        player_a_->setPass(false);
        player_b_->setPass(false);
        if (current_round_%2!=0)
        {
          active_player_=player_a_;
        }
          else active_player_=player_b_;
          map_->setPlayerChips(player_a_);
          map_->setPlayerChips(player_b_);
          if (map_->getMapst()==true)
          {
            map_->printMap();
          }
      }
      std::cout<<"Player "<<active_player_->getID()<<", you have "<<active_player_->getChips();
      std::cout<<" chip(s) left, where and how do you want to place your chips?\n";
    }
    else if (phase_==Phase::MOVEMENT)
    {
      if (active_player_==nullptr)
      {
        player_a_->setPass(false);
        player_b_->setPass(false);
        std::cout<<"------------------\nMovement Phase\n------------------\n";
        if (current_round_%2!=0)
          {
            active_player_=player_b_;
          }
            else active_player_=player_a_;
          if (map_->getMapst()==true)
          {
            map_->printMap();
          }
      }
      std::cout<<"Player "<<active_player_->getID()<<", what do you want to do?\n";
    }
  }
    if (phase_==Phase::END)
    {
      std::cout<<"------------------\nGAME END!"<<std::endl<<std::endl;
      std::cout<<"Player "<<player_a_->getID()<<" claimed "<<map_->getNumFields(player_a_)<<" field(s)!\n";
      std::cout<<"Player "<<player_b_->getID()<<" claimed "<<map_->getNumFields(player_b_)<<" field(s)!\n";
      if ((map_->getNumFields(player_a_))>(map_->getNumFields(player_b_)))
      {
        std::cout<<"\nCongratulations, Player A! You won!\n";
      }
        else if ((map_->getNumFields(player_a_))<(map_->getNumFields(player_b_)))
        {
          std::cout<<"\nCongratulations, Player B! You won!\n";
        }
    }
    if (phase_==Phase::END) return false;
      else return true;
}
void Game::execute(Command command_)
{
  Command::CommandType type;
  type=command_.getType();
  switch (type)
  {
    case Command::CommandType::QUIT:
      break;
    case Command::CommandType::INVALID:
      break;
    case Command::CommandType::WRONG_PARAM:
      break;
    case Command::CommandType::INFO:
      std::cout<<"Player "<< active_player_->getID()<<":\n";
      std::cout<<"You have "<< active_player_->getChips()<<" chip(s) saved!\n";
      std::cout<<"You own "<< map_->getNumFields(active_player_)<<" field(s)!\n";
      std::cout<<"\n";
      break;
    case Command::CommandType::MAP:
      map_->setActive();
      if (map_->getMapst()==true)
      {
        map_->printMap();
      }
      break;
    case Command::CommandType::PASS:
      active_player_->setPass(true);
      break;
    case Command::CommandType::MOVE:
    if (phase_==Phase::MOVEMENT)
    {
      std::vector<std::string>& parameters=command_.getParameters();
      int checkpar=std::stoi(parameters[0]);
      int checkpar2=std::stoi(parameters[1]);
      int checkpar3=std::stoi(parameters[2]);
      int checkpar4=std::stoi(parameters[3]);
      int checkpar5=std::stoi(parameters[4]);
      if (checkpar<0)
      {
        std::cout<<"[ERROR] Invalid amount! Must be a number > 0!\n";
      }
        else if ((checkpar2>map_->getColumns()) || (checkpar3>map_->getRows())
          || (map_->getFields()[checkpar3-1][checkpar2-1]->getPlayer()!=active_player_))
          {
            std::cout<<"[ERROR] Invalid origin!\n";
          }
            else if((map_->getFields()[checkpar3-1][checkpar2-1]->getChips())<checkpar)
            {
              std::cout<<"[ERROR] Invalid amount! Must be a number <= chips on origin field!\n";
            }
              else if((checkpar4>map_->getColumns()) || (checkpar5>map_->getRows()) ||
              (map_->getFields()[checkpar5-1][checkpar4-1]->getWater()==true) || (checkpar4>(checkpar2+1)) ||
              (checkpar4<(checkpar2-1)) || (checkpar5>(checkpar3+1)) || (checkpar5<(checkpar3-1)))
              {
                std::cout<<"[ERROR] Invalid destination!\n";
              }
                else
                {
                  int newchips=map_->getFields()[checkpar3-1][checkpar2-1]->getChips()-checkpar;
                  map_->getFields()[checkpar3-1][checkpar2-1]->setChips(newchips);
                  if (map_->getFields()[checkpar3-1][checkpar2-1]->getChips()==0){
                    map_->getFields()[checkpar3-1][checkpar2-1]->setPlayer(nullptr);
                  }
                  if (map_->getFields()[checkpar5-1][checkpar4-1]->getPlayer()==active_player_ ||
                  map_->getFields()[checkpar5-1][checkpar4-1]->getPlayer()==nullptr)
                  {
                    int a=checkpar;
                    a+=map_->getFields()[checkpar5-1][checkpar4-1]->getChips();
                    map_->getFields()[checkpar5-1][checkpar4-1]->setChips(a);
                    map_->getFields()[checkpar5-1][checkpar4-1]->setPlayer(active_player_);
                  }
                    else if(map_->getFields()[checkpar5-1][checkpar4-1]->getPlayer()!=active_player_){
                      int a=map_->getFields()[checkpar5-1][checkpar4-1]->getChips()-checkpar;
                      if (a<0)
                      {
                        a=a*(-1)-1;
                        map_->getFields()[checkpar5-1][checkpar4-1]->setChips(a);
                        if (map_->getFields()[checkpar5-1][checkpar4-1]->getChips()==0)
                        {
                          map_->getFields()[checkpar5-1][checkpar4-1]->setPlayer(nullptr);
                        }
                        else
                        {
                          map_->getFields()[checkpar5-1][checkpar4-1]->setPlayer(active_player_);
                        }
                      }
                        else
                        {
                          map_->getFields()[checkpar5-1][checkpar4-1]->setChips(a);
                        }
                    }
                    if (map_->getMapst()==true)
                    {
                      map_->printMap();
                    }
                    if (active_player_==player_a_ && player_b_->getPass()==false)
                    {
                      active_player_=player_b_;
                    }
                      else if (active_player_==player_b_ && player_a_->getPass()==false)
                      {
                        active_player_=player_a_;
                      }

                }
    }
      else std::cout<<"[ERROR] Entered command is not valid in this phase!\n";
      break;
    case Command::CommandType::PLACE:
    if (phase_==Phase::PLACEMENT)
    {
      std::vector<std::string>& parameters=command_.getParameters();
      int chips=active_player_->getChips();
      int checkpar=std::stoi(parameters[0]);
      int checkpar2=std::stoi(parameters[1]);
      int checkpar3=std::stoi(parameters[2]);
      if (checkpar<0)
      {
          std::cout<<"[ERROR] Invalid amount! Must be a number > 0!\n";
      }
        else if (chips<checkpar)
        {
            std::cout<<"[ERROR] Invalid amount! Must be a number <= chips in player inventory!\n";
        }
          else if ((checkpar2>map_->getColumns()) || (checkpar3>map_->getRows())
          || (map_->getFields()[checkpar3-1][checkpar2-1]->getPlayer()!=active_player_))
          {
              std::cout<<"[ERROR] Invalid field!\n";
          }
            else
            {
              checkpar+=map_->getFields()[checkpar3-1][checkpar2-1]->getChips();
              map_->getFields()[checkpar3-1][checkpar2-1]->setChips(checkpar);
              chips-=std::stoi(parameters[0]);
              active_player_->setChips(chips);
              if (map_->getMapst()==true)
              {
                map_->printMap();
              }
            }
      if (active_player_->getChips()==0)
      {
        active_player_->setPass(true);
      }
      if (player_a_->getPass()==true && player_b_->getPass()==false)
      {
        active_player_=player_b_;
      }
        else if (player_b_->getPass()==true && player_a_->getPass()==false)
        {
          active_player_=player_a_;
        }
    }
      else std::cout<<"[ERROR] Entered command is not valid in this phase!\n";
      break;
  }
  if (player_a_->getPass()==true && player_b_->getPass()==false)
  {
    active_player_=player_b_;
  }
    else if (player_b_->getPass()==true && player_a_->getPass()==false)
    {
      active_player_=player_a_;
    }
  if (phase_==Phase::PLACEMENT && player_a_->getPass()==true && player_b_->getPass()==true)
  {
    active_player_=nullptr;
    phase_=Phase::MOVEMENT;
  }
    else if (phase_==Phase::MOVEMENT && player_a_->getPass()==true && player_b_->getPass()==true)
    {
      if (current_round_==max_rounds_)
      {
        phase_=Phase::END;
      }
      else{
      active_player_=nullptr;
      phase_=Phase::PLACEMENT;
      current_round_+=1;
      }
    }
      else if (map_->getNumFields(player_a_)==0 || map_->getNumFields(player_b_)==0)
      {
        phase_=Phase::END;
      }
}
Game::~Game()
{
  delete player_a_;
  delete player_b_;

  delete map_;
}