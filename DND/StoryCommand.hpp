//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for story messages output
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef STORYCOMMAND_HPP
#define STORYCOMMAND_HPP
#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
class Game;
class StoryCommand : public Command
{
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  StoryCommand() : Command(false) {};

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
  StoryCommand(const StoryCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~StoryCommand() override {};
};
#endif
