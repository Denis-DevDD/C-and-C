//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for help message output
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
#ifndef HELPCOMMAND_HPP
#define HELPCOMMAND_HPP
class Game;
class HelpCommand : public Command
{
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  HelpCommand() : Command(false) {};

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
  HelpCommand(const HelpCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~HelpCommand() override {};
};
#endif
