//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for looting treasure chests and corpses
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef LOOTCOMMAND_HPP
#define LOOTCOMMAND_HPP

#include "Command.hpp"
#include <iostream>
#include "Game.hpp"

class Game;

class LootCommand : public Command
{
private:
  std::vector<Entity*> entities_to_deallocate;
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  LootCommand() : Command(true){};

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
  LootCommand(const LootCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~LootCommand() override;
};


#endif //LOOTCOMMAND_HPP

