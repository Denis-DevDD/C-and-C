//--------------------------------------------------------------------------------------------------------------------
///
/// Dungeon file includes main information for game such as playable characters, completed rooms and rooms to go
///
///
//--------------------------------------------------------------------------------------------------------------------
#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <vector>
#include "Room.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "PositionLocked.hpp"
#include <string>
#include <fstream>

class Dungeon
{
private:
  Player *playerW_;
  Player *playerR_;
  Player *playerB_;

  int number_of_rooms_;
  int number_of_completed_rooms_;
  std::vector<Room*> rooms_;
  Room *current_room_;
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Constructor of class
  /// @param player avaliable units for player
  /// @param number_of_rooms_ rooms in our dungeon
  /// @param number_of_completed_rooms rooms that player has completed/left them
  /// @param rooms_ pointers to each room
  /// @param current_room current room pointer
  ///
  //--------------------------------------------------------------------------------------------------------------------
  Dungeon(char* dungeon_config, Player *playerW, Player *playerR, Player *playerB);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Setters and getters for parameters of class
  ///
  //
  void setCompletedRoom(int nmbr);
  void setPlayers(Player *playerW, Player *playerR, Player *playerB);
  int getNumberRooms();
  int getCompletedRoom();
  std::vector<Room*> getRooms();


  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Copy constructor of the class
  ///
  /// @return no return
  //
  Dungeon(const Dungeon&) = delete;

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~Dungeon ();
};

#endif
