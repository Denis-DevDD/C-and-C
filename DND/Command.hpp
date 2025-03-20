//----------------------------------------------------------------------------------------------------------------------
//
// The Command class contains a part of command logic and is used as a parental classs to all other 
// commands. Also helps to store the Commands in the CommandParser
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef COMMAND_HPP
#define COMMAND_HPP
class Game;
class Command
{
protected:
  //Settng the Constructor to default
  bool if_action_command_;
public:
  Command(bool if_action) {if_action_command_ = if_action;};
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// execute command that will be overwritten by inherited subcommand classes
  ///
  ///
  /// @return true
  //
  virtual bool execute(Game*) {return true;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Destructor to be ovewritten
  ///
  //
  virtual ~Command() {};

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Copy constructor of the class
  ///
  /// @return no return
  //
  Command(const Command&) = delete;

  bool getIfAction() {return if_action_command_;}
};
#endif
