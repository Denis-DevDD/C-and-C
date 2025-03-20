//---------------------------------------------------------------------------------------------------------------------
//
// This is a basic game that was inspired by Dungeons & Dragons
//
// Group: 035
//
// Authors: Salamat Munipov, Artur Shyutts, Denis Poloiko
//---------------------------------------------------------------------------------------------------------------------
//
#include "Game.hpp"
#include "Exceptions.hpp"

enum Gamereturn
{
  CORRECT = 0,
  WRONG_NUMBER_OF_PARAMETERS = 2,
  WRONG_CONFIG_FILES = 3
};
//---------------------------------------------------------------------------------------------------------------------
///
/// This is a main function that starts the game
///
/// @param argc is an amount of arguments, with wich  the function is called
/// @param argv is a pointer to argument vector, containing story file and dungeon file 
///
/// @return one of Gamereturns
//
int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cout<<"Error: Wrong number of parameters!"<<std::endl;
    return WRONG_NUMBER_OF_PARAMETERS;
  }
  try 
  {
    Game game(argv[1],argv[2]);
    game.GameStart();
  }
  catch (const GameExceptions& e)
  {
    std::cout<<e.what()<<std::endl;
    return WRONG_CONFIG_FILES;
  }
  catch(const std::bad_alloc& e)
  {
    return 1;
  }
  
  return 0;
}
