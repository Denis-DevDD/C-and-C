//--------------------------------------------------------------------------------------------------------------------
///
/// Header file of class Character, this class we need to create "alive" entities such es enemies and players. Some
/// parameters we get from Entity class
///
///
///
//--------------------------------------------------------------------------------------------------------------------
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <map>
#include "Item.hpp"
#include <algorithm>
#include "Entity.hpp"

class Weapon;

class Character : public Entity
{
protected:
  std::string type_id_;
  int max_hp_;
  int current_hp_;
  int armor_value_;
  int strength_;
  int vitality_;
  bool alive_;
  bool if_looted_;
  std::map<Item*, int> inventory_;
  Item* equipped_weapon_;
  Item* equipped_armor_;
  std::map<Item*,int> loot_;

public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Constructor of a class that also uses constructor of a class Entity
  ///
  /// @return no return value
  //
  Character(int max_hp,int armor,int str,int vit);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Character(const Character&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method makes a Character not alive
  ///
  /// @return no return value
  //
  void kill() override;
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method sets the id
  ///
  /// @return no return value
  //
  virtual void setId(std::string id) override;
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method sets the current hp
  ///
  /// @return no return value
  //
  virtual void setHp(int hp) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method adds items in inventory to our character
  ///
  /// @param item contains link to item that we want to add
  /// @param amout contains number of items we would like to add
  ///
  ///
  /// @return no return value
  //
  void addInventory(Item* item, int amount) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method removes items from our character's inventory
  ///
  /// @param item contains link to item that we want to remove
  /// @param amout contains number of items we would like to remove
  ///
  ///
  /// @return no return value
  //
  void remInventory(Item* item, int amount) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Compares two items of the form of std::pair<Item*,int>, returns true if a < b
  ///
  /// @param a
  /// @param b
  ///
  ///
  /// @return bool
  //
  static bool compareIt(const std::pair<Item*, int>& a, const std::pair<Item*, int>& b);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Methode to print our character's loot
  ///
  ///
  /// @return no return
  //
  void printLoot() override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method adds items to our character's loot. We need loot to get items after characters death.
  ///
  /// @param item contains link to item that we want to add
  /// @param amout contains number of items we would like to add
  ///
  ///
  /// @return no return value
  //

  void addLoot(Item* item, int amount) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This method removes items from our character's loot. We need loot to get items after characters death.
  ///
  /// @param item contains link to item that we want to remove
  /// @param amout contains number of items we would like to remove
  ///
  ///
  /// @return no return value
  //
  void remLoot(Item* item, int amount) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Next two methods we need to set current equipment to characters (playable characters).
  ///
  /// @param item contains link to item we want to equip
  ///
  ///
  /// @return no return value
  //

  void setEquippeda(Item* item) override;

  void setEquippedw(Item* item) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// This meithodes we need to check if corpse was looted, so we wont get any errors trying to loot
  /// already looted corpse
  ///
  /// @param item contains link to item we want to equip
  ///
  ///
  /// @return no return value
  //

  void setifWasLooted(bool if_looted) override;

  virtual void fromXtoId() override {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Simple getters that helps us to get information from this class or inherited classes
  ///
  /// @return
  //

  virtual std::string getId() const override;

  virtual int getHP() const override;

  int getVital() const override;

  int getStr() const override;

  std::map<Item*,int> getLoot() override;

  Item* getEquippedw() override;

  virtual Item* getEquippeda() override;

  std::map<Item*, int> getInventory() override;

  int getArmorVal() const override;

  int getMaxHP() const override;

  virtual std::string getName() const override;

  virtual std::string getClassName() const override;

  virtual bool getIfPositionLocked() const override;

  bool getIfDead() const;

  bool ifEnemy() override;

  bool getifWasLooted() override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// default destructor
  ///
  //
  virtual ~Character() = default;
};


#endif //CHARACTER_HPP
