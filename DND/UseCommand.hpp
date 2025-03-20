//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for using items
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef PROJECT_0_USECOMMAND_HPP
#define PROJECT_0_USECOMMAND_HPP

#include "Command.hpp"
#include <iostream>
#include "Game.hpp"

class Game;

class UseCommand : public Command
{
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  UseCommand() : Command(true){};

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
  UseCommand(const UseCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~UseCommand() override {};
};


#endif //PROJECT_0_USECOMMAND_HPP
