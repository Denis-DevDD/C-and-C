#ifndef GAME_HPP
#define GAME_HPP

#include "Map.hpp"
#include "Utils.hpp"
#include "Player.hpp"
#include "Command.hpp"

class Game
{
  public:
    enum class Phase
    {
      PLACEMENT, MOVEMENT, END
    };
  private:
    Map* map_;
    Player* player_a_;
    Player* player_b_;
    int current_round_=1;
    int max_rounds_;
    Phase phase_{Phase::PLACEMENT};
    Player* active_player_;
  public:
    Game(int maximum_rounds, char* config_path);
    static int getRoundNumber(char* string);
    static bool isValidRoundNumber(int rounds);
    static bool isValidConfig(char* config_path);
    void start();
    void execute(Command command);
    bool isRunning();
    void printRound();
    ~Game();
};

#endif