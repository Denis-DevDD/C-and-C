//--------------------------------------------------------------------------------------------------------------------
///
/// Field is a single squere in room. This class we need to store Entities in our room.
///
///
//--------------------------------------------------------------------------------------------------------------------
#ifndef FIELD_HPP
#define FIELD_HPP

#include "Entity.hpp"
#include <iostream>

class Field
{
private:
  int posX_;
  int posY_;
  Entity* current_entity_;

public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Operator so we can output enemies on our field
  /// @param stream some string value that we would like to output also
  /// @param cfield field that we are looking for

  friend std::ostream& operator<<(std::ostream& stream, const Field& field);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// Constructor of class
  /// @param xy coordinates
  /// @param current_entity_ entity that is stored on this field

  Field(int x, int y);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for entity variable
  ///

  void setEntity(Entity *entity);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// simple getters
  ///

  Entity* getEntity();
  int getX();
  int getY();

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy constructor of the class
  ///
  /// @return no return
  //
  Field(const Field&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// desstructor of the class
  ///
  /// @return no return
  //
  ~Field();
};



#endif //FIELD_HPP
