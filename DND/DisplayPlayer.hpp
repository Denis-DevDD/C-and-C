//--------------------------------------------------------------------------------------------------------------------
///
/// DisplayPlayer is responsible for printing player's stats: such as hp, strength, vitality and so on.
///
///
//--------------------------------------------------------------------------------------------------------------------
#ifndef DISPLAYPLAYER_HPP
#define DISPLAYPLAYER_HPP

#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
class Game;
class DisplayPlayer : public Command
{
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Constructor of class
  ///
  ///
  //--------------------------------------------------------------------------------------------------------------------
  DisplayPlayer() : Command(false) {};
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Methode that executes our command
  ///
  ///
  //--------------------------------------------------------------------------------------------------------------------
  bool execute(Game* game) override;
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~DisplayPlayer() override {};

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Copy constructor of the class
  ///
  /// @return no return
  //
  DisplayPlayer(const DisplayPlayer&) = delete;

  friend class Entity;
  friend class player;
};
#endif
