//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for Inventory output
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
#ifndef INVENTORYCOMMAND_HPP
#define INVENTORYCOMMAND_HPP
class Game;
class InventoryCommand : public Command
{
private:
  Room* current_room_;
  std::string id_;
  Player* player_;
  std::map<Item*, int> inv_;
  std::vector<std::pair<Item*, int>> armors_;
  std::vector<std::pair<Item*, int>> weapons_;
  std::vector<std::pair<Item*, int>> consumes_;
  Item* equipped_armor_;
  Item* equipped_weapon_;

public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  InventoryCommand() : Command(false) {};

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
  InventoryCommand(const InventoryCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~InventoryCommand() override {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// saves all necessary variables to this objet
  ///
  /// @param game
  ///
  /// @return no return
  //
  void SafeAllNecessary(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// prints inventory from this object
  ///
  /// @return no return
  //
  void printInv();
};
#endif
