//----------------------------------------------------------------------------------------------------------------------
//
// The command is responsible for AI MOVE
//
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef PLAYCOMMAND_HPP
#define PLAYCOMMAND_HPP

#include "Command.hpp"
#include <iostream>
#include "Game.hpp"
#include <string>
#include "Armor.hpp"
#include <cmath>

class Game;

class PlayCommand : public Command
{
private:
  ///----------------------------------------------------------------------------------------------------------------------
  /// @remark The @param players are in exact Order how they were Initialized in the start of the game
  /// @remark The @param enemies are sorted in ascending alphabetical order (exactly how they are printed under the map)
  //
  std::vector<Player*> players_;
  std::vector<Enemy*> enemies_;

  ///----------------------------------------------------------------------------------------------------------------------
  /// @remark The @param coordinats are in accordance to how Entitys are sorted(read above), first int is Y second is X
  //
  std::vector<std::pair<int, int>> player_coordinats_;
  std::vector<std::pair<int, int>> enemy_coordinats_;

  int action_count_ = 1;

  std::vector<std::pair<std::string,int>> command_rating_;
  std::string chosen_command_;
  std::string chosen_player_;
  std::string chosen_item_;
  std::pair<int, int> chosen_coordinats_;
  std::pair<int, int> buffer_coordinats_loot_;
  std::vector<std::pair <WeaponName, int>> weapon_list_;
  std::vector<std::pair <Armortype, int>> armor_list_;
public:
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// constructor of the class
  ///
  /// @return no return
  //
  PlayCommand() : Command(false), action_count_(1){};

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// executes the command returns bool if its successful
  ///
  /// @return bool
  //
  bool execute(Game* game) override;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// gets all nessesary player and enemy info @remark expand if you want tho
  ///
  /// @return no return
  //
  void getEntityInfo(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// manages what action it is
  ///
  /// @return no return
  //
  void manageActionCount(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates the rating for move command
  ///
  /// @return no return
  //
  void calculateMove(Game *game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates target direction for move command
  ///
  /// @return no return
  //
  void moveDirectionEntity(Game *game,std::pair<int,int> player,std::pair<int,int> entity);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// chooses targets for players and enemies for move command
  ///
  /// @return no return
  //
  void chooseTargetMoveEnemiesLeft(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// returns vector of position locked entities in the room
  ///
  /// @return no return
  //
  std::vector<std::pair<Entity*,std::pair<int,int>>> posLockEntInRoom(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// chooses targets for players and entites for move command
  ///
  /// @return no return
  //
  void chooseTargetMoveNoEnemies(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// chooses targets for players and entites for move Command depending on if there are enemies in the room or not
  ///
  /// @return no return
  //
  void chooseTargetsMove(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates the rating for loot command
  ///
  /// @return no return
  //
  void calculateLoot(Game* game);

  void choseTarget(Game* game);

  void choseCoordinatsOrItem(Game* game);


  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates the rating for Use command
  ///
  /// @return no return
  //
  void calculateUse();

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates the effectivness of player's Items
  ///
  /// @return no return
  //
  void manageItemEffectivness(Player* plr);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates the effectivness of player's Armor and adds them to list
  ///
  /// @return no return
  //
  void manageArmorEffectivness(Item* armor, Player* plr);

  int getFieldval(Field* af);

  std::vector<int> checkforslash(Game* game, int xpos, int ypos);

  std::vector<int> checkforhit(Game* game, int xpos, int ypos);

  std::vector<int> checkforline(Game* game, int xpos, int ypos);

  std::vector<int> checkforthrust(Game* game, int xpos, int ypos);

  std::vector<int> checkforburst(Game* game, int xpos, int ypos);

  std::vector<int> checkforshot(Game* game, int xpos, int ypos);

  int manageFieldValue(Game* game, int y, int x);

  void calculateAttack(Game* game);

  void chooseAttack(Game* game);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// calculates the effectivness of player's weapons and adds them to list
  ///
  /// @return no return
  //
  void manageWeaponEffectivness(Item* weapon, Player* plr);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// quickly checks if a player has a potion with needed resistance
  ///
  /// @return no return
  //
  bool managePotions(Player* plr);

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// choses targets for Loot command
  ///
  /// @return no return
  //
  void choseTargetsLoot(Game* game);

  void choseTargetsUse();


  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// 1. function chooses the item for a player
  /// 2. function choses resistance potions ofr a player
  /// @param plr is a player
  ///
  /// @return 1 for 1.function to stop iterating over players
  /// @return no return for 2. function
  //
  int checkEquippedstuff(Player* plr);
  void checkPotion(Player* plr);
  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// copy-constructor of the class
  ///
  /// @return no return
  //
  PlayCommand(const PlayCommand&) = delete;

  //--------------------------------------------------------------------------------------------------------------------
  ///
  /// destructor of the class
  ///
  /// @return no return
  //
  ~PlayCommand() override = default;
};
#endif

