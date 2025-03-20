//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for map output
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef MAPCOMMAND_HPP
#define MAPCOMMAND_HPP
#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
class Game;
class MapCommand : public Command
{
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  MapCommand() : Command(false) {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// executes the command returns bool if its successful
  ///
  /// @return bool
  //
  bool execute(Game* game) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  MapCommand(const MapCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~MapCommand() override {};
};
#endif
