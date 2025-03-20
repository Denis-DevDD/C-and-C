//----------------------------------------------------------------------------------------------------------------------
//
// Item class is a parent class for all items, contains almost exclusively virtual methods for subclasses.
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>
#include <iostream>
class Character;
class Player;
class Entity;
enum class WeaponName
{
  DAGG, MACE, WARH, HAXE, GAXE, RAPI, SSWD, LSWD, GSWD, SBOW, LBOW,
  LCRS, HCRS, QFIR, QCLD, QACD, QFRC
};

enum class Armortype
{
  LARM = 1, BPLT = 4, CHML = 6, PARM = 8
};
enum class SubWeaponType
{
  BOW, CROSSBOW, MELEE
};
enum class DamageType
{
  PHYSICAL, COLD, FIRE, ACID, FORCE, NONE
};
enum class ItemType
{
  WEAPON, CONSUMABLE, ARMOR
};
enum class AttackType
{
  MELEE, RANGED
};
enum class DamagePattern
{
  HIT, THRUST, SLASH, LINE, SHOT, BURST
};
class Item
{
protected:
  std::string name_;
  ItemType item_type_;
public:

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  Item(std::string& name) {name_ = name;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Item(const Item&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the name
  ///
  /// @return std::string
  //
  std::string getName()
  {
    return name_;
  }
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  virtual ~Item() {}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return SubWeaponType
  //
  virtual SubWeaponType getSubType() {return SubWeaponType::MELEE;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return DamageType
  //
  virtual DamageType getDType(){return DamageType::NONE;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return AttackType
  //
  virtual AttackType getaType(){return AttackType::MELEE;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return int
  //
  virtual int damagecalc(Character*){return 0;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return DamagePattern
  //
  virtual DamagePattern getPattern() {return DamagePattern::HIT;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return int
  //
  virtual int getArmValue() const {return 0;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the item type
  ///
  /// @return ItemType
  //
  ItemType getItemType() const {return item_type_;}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return std::string
  //
  virtual std::string getFullName() const {return "None";}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return no return
  //
  virtual void setArmValue(Entity*) {}
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return no return
  //
  virtual void usePotion(Player*) {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return no return
  //
  virtual WeaponName getWName() {return WeaponName::DAGG;};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return no return
  //
  virtual Armortype getArmName() {return Armortype::BPLT;};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// virtual method,that gets overwritten
  ///
  /// @return no return
  //
  virtual DamageType getDmgREsistanmces() {return DamageType::NONE;}
};



#endif //ITEM_HPP
