//----------------------------------------------------------------------------------------------------------------------
//
// The Game class contains the main functionality of the game and game logic
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef GAME_HPP
#define GAME_HPP
#include <map>
#include <string>
#include "CommandParser.hpp"
#include "Dungeon.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "Item.hpp"
class Command;
class CommandParser;
enum class Endings
{
  LOST, WON, FLEED,
};
enum GamePhase {ENEMYPHASE, PLAYERPHASE, END, QUIT, EF};
class Game
{
private:
  //phase
  GamePhase phase_;
  //story output
  bool story_output_;
  //map output
  bool map_output_;
  //map for story config
  std::map<std::string, std::string>* storycon;
  //dungeon
  Dungeon *dungeon_;
  //current room of players
  Room* current_room_;
  //command parser
  CommandParser* parser_;
  bool last_command_action_;
  //players
  Player *playerW_;
  Player *playerR_;
  Player *playerB_;
  //amount of players
  int total_actions_;
  bool changed_room;
  int amount_of_plrs_left_;
  int amount_of_plrs_;
  Endings ending_;
  ///dont ask, i had to do it
  std::vector<Player*> players_;
  //Item vector
  std::map<std::string, Item*> itemlinks_;
  std::map<std::string, Item*>* all_items_;

public:

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Constructor of the game calss
  ///
  /// @param dungeon_config is a pointer to char that contains dungeon file path
  /// @param story_config is a pointer to char that contains story file path
  ///
  /// @return no return value
  //
  Game(char* dungeon_config, char* story_config);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Destructor of the game calss, deallocates all configs and parser
  ///
  //
  ~Game();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This function reads Commands and catches exceptions if there are any
  ///
  /// @return true for action, false for display
  //
  bool ReadCommand();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Checks if story config is valid
  ///
  /// @param story_config is a pointer to char that contains story file path
  ///
  /// @return bool
  //
  bool isValidStoryCon(char* stroy_config);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Parsing the story config
  ///
  /// @param story_config is a pointer to char that contains story file path
  ///
  /// @return bool
  //
  void parseConfig(char* story_config);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// Checks if dungeon config is valid
  ///
  /// @param dungeon_config
  ///
  /// @return bool
  //
  bool isValidDungeonConfig(char* dungeon_config);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This initializes the amount of players
  ///
  /// @param return_value a refference to a return value of game start to end the game in case of quit command
  ///
  /// @return no return value
  //
  void inititalizeAmountPlayers(int& return_value);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This initializes all 3 players names accordingly
  ///
  /// @return 0 for successfull -1 for quit
  //
  int inititalizePlayersNames();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method creates all players accordinlgy to chosen class and name
  ///
  /// @return 1 if succesfull, -1 for quit
  //
  int createPLayers(std::vector<std::string> names, int i, int& w_players, int& b_players, int& r_players);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method prints player at the start of the game
  ///
  /// @return 1 if succesfull, -1 for quit
  //
  void printPLayersStart();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method contains main game loop and loogic
  ///
  /// @return 0 in case of normal ending, and -1 in case of QUIT
  //
  int GameStart();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method does main loop moving throught the Rooms
  ///
  /// @return 0
  //
  int mainGameLoop();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This method does the loop in the Room
  ///
  /// @return 0
  //
  int doRoomLoop();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// This prints all needed info ab Room
  ///
  /// @return no return
  //
  void printRoomInfo();
  
  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter of phase
  ///
  /// @return no return
  //
  void setPhase(GamePhase phase)
  {
    phase_ = phase;
  }

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// allocates all nesessary items
  ///
  /// @return no return
  //
  void createItems();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for items
  ///
  /// @return no return
  //
  std::map<std::string, Item*> getItems();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter parser
  ///
  /// @return no return
  //
  CommandParser* getParser() {return parser_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// checks if all players are dead or all enemies are dead
  /// or if Dungeon is comleted
  ///
  /// @return no return
  //
  void endOfAttackCheck();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for players_
  ///
  ///
  /// @return std::vector<Player*>
  //
  std::vector<Player*> getPlayers() {return players_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for story_output_ status
  ///
  ///
  /// @return bool
  //
  bool getStoryOutput() {return story_output_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for story_output_ status
  ///
  /// @param b
  ///
  /// @return no return
  //
  void setStoryOutput(bool b) {story_output_ = b;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for map_output_ status
  ///
  ///
  /// @return bool
  //
  bool getMapOutput() {return map_output_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for map_output_ status
  ///
  /// @param b
  ///
  /// @return no return
  //
  void setMapOutput(bool b) {map_output_ = b;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for dungenon
  ///
  ///
  /// @return Dungeon*
  //
  Dungeon* getDungeon() {return dungeon_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the current_room_
  ///
  ///
  /// @return Room*
  //
  Room* getCurrentRoom() {return current_room_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for the amount of players
  ///
  ///
  /// @return int
  //
  int getAmountOfPlayer() {return amount_of_plrs_;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the amount of left players
  ///
  /// @param left_plrs
  ///
  ///
  /// @return no return
  //
  void setLeftPlayers(int left_plrs) {amount_of_plrs_left_ = amount_of_plrs_left_+left_plrs;}

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// setter for the current_room_ and spawner of players at the door
  ///
  /// @param room
  /// @param Entity*
  ///
  ///
  /// @return no return
  //
  void setCurrentRoom(Room* room, Entity*);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// getter for player based on abbreviation
  ///
  /// @param pabbreviation
  ///
  ///
  /// @return Player*
  //
  Player* getPlayer(std::string pabbreviation);

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// prints the message before entering the room
  ///
  /// @return no return
  //
  void beforeRoomPrint();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// returns the story message based on its key
  ///
  /// @param key
  ///
  /// @return std::string
  //
  std::string getStoryMessage(std::string key)
  {
    return storycon->find(key)->second;
  }

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// ending of the game
  ///
  /// @return no return
  //
  void endOfGame();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// ending of the game message
  ///
  /// @return std::string
  //
  std::string endMsg();

  //---------------------------------------------------------------------------------------------------------------------
  ///
  /// saves the result into file
  ///
  /// @return no return
  //
  void saveFiel();

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy constructor of the class
  ///
  /// @return no return
  //
  Game(const Game&) = delete;
};


#endif
