//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for player movement in the room
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef MOVECOMMAND_HPP
#define MOVECOMMAND_HPP
#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
class Game;
class MoveCommand : public Command
{
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  MoveCommand() : Command(true) {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// executes the command returns bool if its successful
  ///
  /// @return bool
  //
  bool execute(Game* game) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// prints the message about the movement of the player
  ///
  /// @return no return
  //
  void print(int x_s, int y_s, Entity* moved);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  MoveCommand(const MoveCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~MoveCommand() override {};
};
#endif
