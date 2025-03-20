//----------------------------------------------------------------------------------------------------------------------
//
// PostionLocked class is the class for not-alive entities such as doors and treasure chests
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef POSITIONLOCKED_HPP
#define POSITIONLOCKED_HPP

#include "Entity.hpp"
#include <string>
#include <map>
#include <algorithm>
#include "Functions.hpp"

class Room;

class PositionLocked : public Entity
{
private:
  std::string type_;
  bool locked_;
  int dice_to_beat_;
  int leads_to_room_id_;
  Room *leads_to_room_ptr_;
  std::map<Item*, int> loot_;
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  PositionLocked(std::string type, bool locked, int dice_to_beat,int leads_to_room_id) : Entity()
  {
    type_ = type;
    locked_=locked;
    dice_to_beat_=dice_to_beat;
    leads_to_room_id_ = leads_to_room_id;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for entity id
  ///
  /// @return std::string
  //
  std::string getId() const override
  {
    return type_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the pointer which leads to the room through the door
  ///
  /// @return no return
  //
  void setLeadsToRoomPtr(Room *ptr) override
  {
    leads_to_room_ptr_=ptr;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the loot of the treasure chest
  ///
  /// @return std::map<Item*,int>
  //
  std::map<Item*, int> getLoot() override
  {
    return loot_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// adds a loot of the given amount
  ///
  /// @param item
  /// @param amount
  ///
  /// @return no return
  //
  void addLoot(Item* item, int amount) override
  {
    loot_.insert({item,amount});
  }
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// removes an item from loot
  ///
  /// @param item
  ///
  /// @return no return
  //
  void eraseLoot(Item* item) override
  {
    loot_.erase(item);
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the leads_to_room_id_ of the door
  ///
  /// @return int
  //
  int getNumber() const override {return leads_to_room_id_;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  PositionLocked(const PositionLocked&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~PositionLocked() = default;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the locked_
  ///
  /// @return bool
  //
  bool getIfLocked() override {return locked_;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the leads_to_room_id_ of the door
  ///
  /// @return int
  //
  int leadsTo() override
  {
    return leads_to_room_id_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the dice to beat to open the chest
  ///
  /// @return int
  //
  int getDiceToBeat() override
  {
    return dice_to_beat_;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the locked status
  ///
  /// @return no return
  //
  void setLock(bool a) override
  {
    locked_ = a;
  }

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// prints loot of the treasure chest
  ///
  /// @return no return
  //
  void printLoot() override;
};
#endif //POSITIONLOCKED_HPP
