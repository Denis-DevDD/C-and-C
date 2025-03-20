//----------------------------------------------------------------------------------------------------------------------
//
// Enemy is the class for enemy characters, contains info and logic about them
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "Character.hpp"
#include <map>
#include "Item.hpp"
#include "Weapon.hpp"
#include "Player.hpp"


class Enemy : public Character
{
private:
  std::string full_name_;
  int id_;
  std::vector<Field*> affected_fields_;
  bool if_affecting_;
public:
  friend std::ostream& operator<<(std::ostream& srteam, const Enemy* enemy);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  Enemy(int max_hp, int armor, int str, int vit, int id,std::string type_id);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the name
  ///
  /// @return std::string
  //
  std::string getId() const override
  {
    return type_id_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the int id of the enemy
  ///
  /// @return int
  //
  int getNumber() const override
  {
    return id_;
  }

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method forces enemy to move
  ///
  /// @return no return
  //
  void doMove(Room* room);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method calculates what PLayer to atttack
  ///
  /// @return Target Player
  //
  Player* chooseTarget(Room* room, std::vector<Player*> players);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method chooses a weapon for Enemy
  ///
  /// @return Weapon
  //
  Item* chooseWeapon(Room* room, Player* player);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns fullname by the id
  ///
  /// @return std::string
  //
  std::string nametoFullName(std::string& name);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns fullname
  ///
  /// @return std::string
  //
  std::string getName() const override {return full_name_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method makes Enemy perform an action
  ///
  /// @return no return
  //
  void doAction(Room* room, std::vector<Player*> player);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method makes Enemy perform an Attack
  ///
  /// @return no return
  //
  void doAttack(int x, int y, int yline, int dif, Item* att, Room* curr_room);

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
  void attackLine(int x, int y, int yline, int dif, Item* att, Room* curr_room, int damageam);
  void attackThrust(int x, int y, int yline, int dif, Item* att, Room* curr_room, int damageam);
  void attackSlash(int x, int y, int yline, int dif, Item* att, Room* curr_room, int damageam);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// deals damage to the coordinates
  /// @param x
  /// @param y
  /// @param att our equipped weapon that will deal damage
  /// @param room room where our attackcommand performs(we need this to get pointer to entity on attacked field)
  /// @param damageam damage amout that our weapon performs
  ///
  /// @return no return
  //
  void damagedeal(int x, int y, Item* att, Room* room,  int damageam);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// copy constructor of the class
  ///
  /// @return no return
  //
  Enemy(const Enemy&) = delete;

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~Enemy() override = default;

};


#endif //ENEMY_HPP
