#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP

#include "Item.hpp"
#include <string>
#include "Player.hpp"
enum class Type
{
  POTION, AMMUNITION
};

enum class SubType
{
  NHEP, GHEP, SHEP, FIRS, CORS, FORS, ACRS, ARRW, BOLT
};

class Consumable : public Item
{
private:
  Type type_;
  SubType subtype_;
  DamageType damage_res_;
  std::string full_name_;
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns weapons sub-type based on name
  ///
  /// @return Subtype
  //
  SubType nametoSubType(std::string name);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for sub-type
  ///
  /// @return no return
  //
  void setType(SubType);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  Consumable(std::string name) : Item(name)
  {
    damage_res_ = DamageType::NONE;
    item_type_ = ItemType::CONSUMABLE;
    subtype_ = nametoSubType(name);
    full_name_ = nameToFullName(name);
    setType(subtype_);
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the full name
  ///
  /// @return std::string
  //
  std::string getFullName() const override{return full_name_;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns full name based on short name
  ///
  /// @return std::string
  //
  std::string nameToFullName(std::string name);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// uses potion
  ///
  /// @return no return
  //
  void usePotion(Player* player) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the resistances type
  ///
  /// @return std::string
  //
  DamageType getDmgREsistanmces() override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
   ~Consumable() override {};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Consumable(const Consumable&) = delete;
};

#endif //CONSUMABLE_HPP
