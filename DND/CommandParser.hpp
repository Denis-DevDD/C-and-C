//----------------------------------------------------------------------------------------------------------------------
//
// The CommandParser class is served to store all avaible commands and to read the commands
//
//---------------------------------------------------------------------------------------------------------------------
//

#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <string>
#include <map>
#include <vector>
#include "Command.hpp"
#include "Game.hpp"
class Game;
class CommandParser
{
private:
  std::map<std::string, Command*> commands_;
  std::vector<std::string> split_input_;
  std::vector<int> position_;
  bool exception_thrown_;

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that removes Whitespaces at the end of the string, we took this metod from A1 CommandLine
  ///
  /// @param user_input is a refference to user input
  ///
  /// @return no return value
  //
  void removeEndsWhitespaces(std::string& user_input);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that removes Whitespaces at the start of the input, we took this metod from A1 CommandLine
  ///
  /// @param user_input is a refference to user input
  ///
  /// @return no return value
  //
  void removeBeginingsWhitespaces(std::string& user_input);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that splits the user input into vector of strings, we took ispiration from A1 method in 
  /// CommandLine, however we changed it a bit to better fit our needs
  /// for the record: i know how it works and i can explqain every step of it
  ///
  /// @param user_input is a refference to user input
  ///
  /// @return no return value
  //
  void splitStringtoVector(const std::string& user_input);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that extracts postition from a command
  ///
  /// @param split_input is a split input
  ///
  /// @return no return value
  //
  void extractPositionParameters(std::vector<std::string> split_input);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// splits a string with commas into another vector with 2 arguments and without comma
  ///
  /// @param string_to_split is a string to split
  ///
  /// @return the vector contain all split strings
  //
  void splitStringByComma(std::string string_to_split, std::vector<std::string>& all_split_strings);

public:

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return std::vector<int>
  //
  CommandParser() = default;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the commands
  ///
  /// @return std::map<std::string,Command*>
  //
  std::map<std::string, Command*> getAllCommands();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that registers coommands, stroing them in CommandParser map
  ///
  /// @param name_of_command is a nema of the command to be registered
  /// @param command is a pointer to the command to be registered
  ///
  /// @return no return value
  //
  void registerCommand(const std::string name_of_command, Command* command);


  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that reads the command and stores its parameters in vectors
  ///
  /// @return no return value
  //
  int readCommand();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// a method that registers coommands, stroing them in CommandParser map
  ///
  /// @param name_of_command is a nema of the command to be registered
  /// @param command is a pointer to the command to be registered
  ///
  /// @return no return value
  //
  bool executeCommand(std::string user_input, Game* game);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Destructor of the CommandParser calss, deletes all commands, that were stored on the heap
  ///
  /// @return no return value
  //
  ~CommandParser();

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  CommandParser(const CommandParser&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for user input
  ///
  /// @return std::vector<std::string>
  //
  std::vector<std::string> getUserInput();

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the position
  ///
  /// @return std::vector<int>
  //
  std::vector<int> getCrd();

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns exception_thrown_
  ///
  /// @return bool
  //
  bool getIfThrow() {return exception_thrown_;}

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// sets Parser Values
  /// @param command is a command from parser to set
  /// @param id is an id of player
  /// @param params coordinats
  ///
  /// @return no return
  //
  void setParsersValues(std::string& command, std::string& Id, std::string item, std::pair<int, int>& params);
};
#endif
