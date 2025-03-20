//----------------------------------------------------------------------------------------------------------------------
//
// Player is the class for player characters, contains info and logic about them
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include <string>
#include "Character.hpp"
#include "Field.hpp"

class Player : public Character
{
protected:
  std::string name_;
  std::string name_of_class_;
  bool fleed_;
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  Player(std::string name, int max_hp, int armor, int str, int vit, std::string id);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// checks if the player has an ammo of the given type
  ///
  /// @param name
  ///
  /// @return bool
  //
  bool checkAmmunition(std::string name);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the name
  ///
  /// @return std::string
  //
  std::string getName() const override
  {
    return name_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the class
  ///
  /// @return std::string
  //
  std::string getClassName() const override
  {
    return name_of_class_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the Id
  ///
  /// @return std::string
  //
  std::string getId() const override
  {
    return type_id_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the inventory
  ///
  /// @return std::string
  //
  std::map<Item*, int>* getInv()
  {
    std::map<Item*, int>* inventory = &inventory_;
    return inventory;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the fleed_
  ///
  /// @return bool
  //
  bool getIfFleed() {return fleed_;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the fleed_
  ///
  /// @param fleed
  ///
  /// @return no return
  //
  void setIfFleed(bool fleed) override {fleed_ = fleed;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Player(const Player&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~Player() override = default;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// finds the player in the given room
  ///
  /// @param room
  ///
  /// @return Field*
  //
  Field* findMySelf(Room* room);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// overwrites the id to the one of the class
  ///
  /// @return no return
  //
  void fromXtoId() override;
};
  
  


#endif //PLAYER_HPP
