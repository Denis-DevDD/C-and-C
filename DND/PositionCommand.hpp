//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for positions display
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef POSITIONCOMMAND_HPP
#define POSITIONCOMMAND_HPP
#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
class Game;
class PositionCommand : public Command
{
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  PositionCommand() : Command(false) {};

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
  PositionCommand(const PositionCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~PositionCommand() override {};
};
#endif
