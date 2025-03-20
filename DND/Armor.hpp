//---------------------------------------------------------------------------------------------------------------------
///
/// Header file for section "Armor" that includes it's constructor and some simple getters.
///
///
///
///


#ifndef ARMOR_HPP
#define ARMOR_HPP

#include "Item.hpp"
#include "Character.hpp"
#include "Entity.hpp"

class Armor : public Item
{
  private:
  Armortype armtype;
  int armor_value_;
  std::string full_name_;

  public:
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Function nametoArmtype provides us a possibility to fill our constructor further.
  ///
  /// @param name abbreviation of Armor type
  /// @param typenames map that we use to get Armortype enum class depending on abbreviation that we got with @param name
  /// @param pair gets value of map where our abbreviation is met
  ///
  /// @return Armortype enum class
  ///
  Armortype nametoArmtype(std:: string& name);
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Functon to get full name of armor so we can use it in output
  ///
  /// @param name abbreviation of Armor type
  /// @param typenames map to get full name depending on abbreviation
  /// @param pair gets value of map where our abbreviation is met
  ///
  /// @return full name of armor as string
  ///
  std::string nameToFullName(std::string name);
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Construcor of class setting its base armor value using switch methode and Armortype nametoArmtype function
  ///
  /// @param name abbreviation of Armor type
  /// @param armtype variable for Armortype enum class
  /// @param armorvalue variable for base armor value without buffs from strength and vitality
  /// @param ItemType  variable that we need in future to see what type of item (consumable, weapon or armor) it is
  ///
  Armor (std::string name);
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Function to set final armor value depending on characters vitality or strength
  ///
  /// @param Char class pointer on character so we can get its vitality or strength
  /// @param armtype variable for Armortype enum class
  /// @param armorvalue variable that we expand now using characters stats
  ///
  ///
  virtual void setArmValue(Entity* Char) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~Armor() override {}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Armor(const Armor&)=delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// convertor for Name of Armor
  ///
  /// @return name of armor
  //
  static std::string aNameToName(Armortype);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Simple getters, so we can use our class in main function
  ///
  /// 1. func @return armor_value
  /// 2. func @return full_name
  /// 3. func @return Armortype
  ///
  ///
  virtual std::string getFullName() const override;
  virtual int getArmValue() const override;
  virtual Armortype getArmName() override;
};

#endif //ARMOR_HPP
