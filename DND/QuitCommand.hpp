//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for quitting
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "Command.hpp"
#ifndef QUITCOMMAND_HPP
#define QUITCOMMAND_HPP
#include "Game.hpp"
class Game;

class QuitCommand : public Command
{
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  QuitCommand() : Command(false) {};

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
  QuitCommand(const QuitCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~QuitCommand() override {};
};

#endif
