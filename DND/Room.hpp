//----------------------------------------------------------------------------------------------------------------------
//
// The Room class contains the information about the room and logic for parsing the dungeon config
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef ROOM_HPP
#define ROOM_HPP
#include "Field.hpp"
#include <vector>
#include <string>
#include "Functions.hpp"
#include "Entity.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PositionLocked.hpp"
#include "Player.hpp"
#include <sstream>

class Room
{
private:
  int room_id_;
  int dimension_X_;
  Field* executor_field_;
  int dimension_Y_;
  static int executor_x_;
  static int executor_y_;
  std::vector<std::vector<Field*>> fields_;
  bool completion_status_;
  int number_of_enemies_;
  std::vector<Enemy*> enemies_;
public:
  friend std::ostream& operator<<(std::ostream& srteam, const Room* room);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  /// @param line line of the given room from dungeon_config
  ///
  /// @return no return
  //
  Room(std::string line);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method prints all alive enemies and their hp
  ///
  /// @return no return value
  //
  void printAllEnemies();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the id
  ///
  /// @return int
  //
  int getId() {return room_id_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the fields 2d vector
  ///
  /// @return std::vector<std::vector<Field*>>
  //
  std::vector<std::vector<Field*>> getFields()
  {
    return fields_;
  }

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method finds a Field with necessary Player
  ///
  /// @param id is an id of the Player
  ///
  /// @return Field
  //
  Field* getNeededRoom(std::string id);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the completion status
  ///
  /// @return bool
  //
  bool getIfCompleted() {return completion_status_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the completion status
  /// @param completion_status
  ///
  /// @return no return
  //
  void setCompleted() {completion_status_ = true;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the coordinates of the door with the given id
  ///
  /// @param leads_to_room id needed
  ///
  /// @return std::pair<int,int>
  //
  std::pair<int,int> getNeededDoor(int leads_to_room);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// checks if the given coordinates are inbound
  /// @param y is y coordinaate
  /// @param x is x Coordinate
  /// @param dim_y is y dimension
  /// @param dim_x is x dimension
  ///
  /// @return std::pair<int,int>
  //
  bool inBound(int y, int x,int dim_x, int dim_y);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// returns first empty field around target clockwise
  ///
  /// @param y is y coordinaate
  /// @param x is x Coordinate
  ///
  /// @return Field*
  //
  Field* findFirstFreeClockwise(int y, int x);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// returns first empty field around target clockwise
  ///
  /// @param y is y coordinaate
  /// @param x is x Coordinate
  ///
  /// @return Field*
  //
  Field* findFirstFreeClockwiseExp(int y, int x);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method finds a Field with necessary Player
  ///
  /// @param field is a field of player to move\
  /// @param y is y coordinaate
  /// @param x is x Coordinate
  ///
  /// @return no return
  //
  void canMoveTO(Field* field, int y, int x);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method checks if the given field is lootable
  ///
  /// @param field is a field of player to move\
  /// @param y is y coordinaate
  /// @param x is x Coordinate
  ///
  /// @return no return
  //
  void canLoot(Field* field,int y, int x);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method checks if the given field is lootable
  ///
  /// @param field is a field of player to move\
  /// @param y is y coordinaate
  /// @param x is x Coordinate
  ///
  /// @return no return
  //
  void checkRange(int y, int x);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the dimension_X_
  ///
  /// @return int
  //
  int getDimX() const {return dimension_X_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the dimension_Y_
  ///
  /// @return int
  //
  int getDimY() const {return dimension_Y_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the executor_y_
  ///
  /// @return no return
  //
  void setExecutorY(int y) {executor_y_ = y;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the executor_x_
  ///
  /// @return no return
  //
  void setExecutorX(int x) {executor_x_ = x;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the enemies in the room
  ///
  /// @return std::vector<Enemy*>
  //
  std::vector<Enemy*> getEnemies() const {return enemies_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~Room();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// returns filed with the needed enemy
  ///
  /// @param enemy
  ///
  /// @return Field*
  //
  Field* getNeededEnemy(Enemy* enemy);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// checks if the givn coordinates are in border
  ///
  /// @param y y coordinate
  /// @param x x coordinate
  ///
  /// @return bool
  //
  bool inBorders(int y, int x);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// unlocks all doorss
  ///
  /// @return no return
  //
  void unlockDoors();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// removes players
  ///
  /// @return no return
  //
  void removePlayers();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// returns a field with a given entity
  /// @param ent entity
  ///
  /// @return Field*
  //
  Field* findEntity(Entity* ent);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// returns a pointer to the first free clockwise field
  /// @param y coordinate
  /// @param x coordinate
  ///
  /// @return Field*
  //
  Field* findFirstFreeClockwisePlr(int y, int x);

  Field* findEntById(std::string id, std::vector<std::pair<int, int>>& added_coords);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  Room(const Room&) = delete;
};


#endif //ROOM_HPP
