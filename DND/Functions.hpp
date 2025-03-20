//----------------------------------------------------------------------------------------------------------------------
//
// The functions class contains usefull functions
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include "Enemy.hpp"
#include "Player.hpp"
class Functions
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  //Constructor, Copy Constructor and Destructor are deleted since an object of this class will never be created
  //
  Functions() = delete;
  Functions(const Functions&) = delete;
  ~Functions() = delete;

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that reads converts string to integer
  ///
  /// @param string_to_convert is a string that needs to be converted, throws customs exseption if string isnt integer
  ///
  /// @return converted intger
  //
  static int stringToInteger(std::string string_to_convert);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method turns all letters to uppercase
  ///
  /// @param string_to_convert is a string that needs to be converted
  ///
  //
  static void allToUpper(std::string& string_to_convert);


  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method turns all letters to uppercase
  ///
  /// @param string_to_convert is a string that needs to be converted
  ///
  //
  static void allToLower(std::string& string_to_convert);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that checks if input for amount of players was correct
  ///
  /// @param input_amount is users input
  ///
  /// @return different values base on result
  //
  static int checkInitialAmount(std::string& input_amount);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that checks if input for class of players was correct
  ///
  /// @param w_players amount of Wizzards
  /// @param b_players amount of Barbarians
  /// @param r_players amount of Rogues
  ///
  /// @return players choice
  //
  static int doClassInput(int& w_players, int& b_players, int& r_players);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that checks if input for amount of players was correct
  ///
  /// @param X_players a number of players of this class
  ///
  /// @return different values base on result
  //
  static bool compareEnemies(const Enemy* a, const Enemy* b);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that checks if input for amount of players was correct
  ///
  /// @param a pair of Item and amount 1
  /// @param b pair of Item and amount 2
  ///
  /// @return if a <b
  //
  static bool compareItems(const std::pair<Item*, int>& a, const std::pair<Item*, int>& b);

  static bool canHit(int y_f, int x_f, int y_s, int x_s);

  static bool compareFields(Field* a, Field* b);

  static void Damagecheck(int& dmg, const int health);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that compares players based on their distances
  ///
  /// @param a pair of player and distance 1
  /// @param b a pair of player and distance 2
  ///
  /// @return if a < b
  //
  static bool comparePlayers(const std::pair<Player*, int>& a, const std::pair<Player*, int>& b);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that checks if positions are adjecent
  ///
  /// @param my_x is x of firct Entity
  /// @param my_y is yof first Entity
  /// @param other_x is x of other Entity
  /// @param other_y is y of other Entity
  ///
  /// @return true if they are adjecent
  //
  static bool getPositionsAdjacent(int my_x, int my_y, int other_x, int other_y);
};
#endif
