//--------------------------------------------------------------------------------------------------------------------
///
/// AttackCommand is responsible for attack action in our game. Its also useful for players and enemy npcs
///
///
//--------------------------------------------------------------------------------------------------------------------
#ifndef ATTACKCOMMAND_HPP
#define ATTACKCOMMAND_HPP

#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
#include "Field.hpp"
class Game;
class AttackCommand : public Command
{
  private:
  bool if_affecting_;
  std::vector<Field*> affected_fields_;
  public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Constructor of our class that also inherits command class
  ///
  ///
  //
  AttackCommand() : Command(true) {};
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// damagedeal function. We need this to deal damage to our target
  ///
  /// @param xy we need these to find the coordinates of target
  /// @param att our equipped weapon that will deal damage
  /// @param room room where our attackcommand performs(we need this to get pointer to entity on attacked field)
  /// @param damageam damage amout that our weapon performs
  //
  void damagedeal(int x, int y, Item* att, Room* room, int damageam);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// three functions that performs our damage pattern(it contains functionallity to find coordinates of attack besides
  /// main target field)
  ///
  /// @param xy we need these to find the coordinates of target
  /// @param y0 attacker y coordinate
  /// @param dif differense between x coordinates of attacker and target so we will be able to find attack direction
  /// @param att our equipped weapon that will deal damage
  /// @param room room where our attackcommand performs(we need this to get pointer to entity on attacked field)
  /// @param damageam damage amout that our weapon performs
  //
  void attackThrust(int x, int y, int y0, int dif, Item* att, Room* curr_room, int damageam);
  void attackLine(int x, int y, int y0, int dif, Item* att, Room* curr_room, int damageam);
  void attackSlash(int x, int y, int y0, int dif, Item* att, Room* curr_room, int damageam);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// function that we need to activate our command
  ///
  //
  bool execute(Game* game) override;
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// print function to display done attack action.
  /// @param executor attack performer
  /// @param target_y_x target coordinates
  /// @param attcw attack weapon
  /// @param room room where attack is performed
  //
  void printAffected(Player* executor, int target_y, int target_x, Item* attcw, Room* room);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  AttackCommand(const AttackCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~AttackCommand() override;
};
#endif
