//----------------------------------------------------------------------------------------------------------------------
//
// The Weapon class contains logic for Weapons
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Item.hpp"
#include <map>


class Weapon : public Item
{
protected:
  std::string full_name_;
  WeaponName w_name_;
  AttackType attack_type_;
  DamageType damage_type_;
  DamagePattern damage_pattern_;
  SubWeaponType sub_type_;
  int damage_amount_;
  int rolls_;
  int last_max;
  int result_;

public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Getter for the name
  ///
  /// @return std::string full name of the item
  //
  std::string getFullName() const override {return full_name_;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns the Weapon based on its name
  ///
  /// @param name
  ///
  /// @return WeaponName name
  //
  WeaponName nametoWname(std::string& name);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns Weapons full name
  ///
  /// @param name
  ///
  /// @return std::string full name of the weapon
  //
  std::string nametoFullName(std::string& name);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns weapons subtype
  ///
  /// @return bow, crosswbow or melee
  //
  SubWeaponType nameToSubType(WeaponName);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  Weapon(std::string name, AttackType atcktype, DamageType dmgtp, DamagePattern dmgptrn);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for weapon sub type
  ///
  /// @return SubWeaponType
  //
  SubWeaponType getSubType() override {return SubWeaponType::MELEE;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates damage based on a given weapon
  ///
  /// @return int damage
  //
  int damagecalc(Character* chr) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for attack type
  ///
  /// @return AttackType
  //
  AttackType getaType() override
  {
    return attack_type_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for WName
  ///
  /// @return DamagePattern
  //
  WeaponName getWName() override
  {
    return w_name_;
  }
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for damage pattern
  ///
  /// @return DamagePattern
  //

  DamagePattern getPattern() override
  {
    return damage_pattern_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the damage type
  ///
  /// @return DamageType
  //
  DamageType getDType() override
  {
    return damage_type_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Weapon(const Weapon&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  virtual ~Weapon() {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns random number to max
  ///
  /// @return size_t random
  //
  size_t rand(int max);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// finds neede Name according to Wname
  ///
  /// @return actual name of the Weapon
  //
  static std::string wNameToName (WeaponName);
};


#endif //WEAPON_HPP
