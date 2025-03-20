#include "Command.hpp"
#include <iostream>
#include <vector>
#include <cstring>

bool Command::isQuit()
{
  if (type_==CommandType::QUIT)
  {
    return true;
  } else return false;
}
void Command::setType(CommandType type)
{
  type_=type;
}
std::vector<std::string>& Command::getParameters()
{
  return parameters_;
}
Command::CommandType Command::getType() const
{
  return type_;
}
Command::Command(std::vector<std::string>& input)
{
  std::string command = input[0];
  for (char& c : command)
  {
    c=std::toupper(c);
  }
  if (command == "MOVE")
  {
    type_=CommandType::MOVE;
  }
    else if (command == "PLACE")
    {
      type_=CommandType::PLACE;
    }
      else if (command == "PASS")
      {
        type_=CommandType::PASS;
      }
        else if (command == "INFO")
        {
          type_=CommandType::INFO;
        }
          else if (command == "MAP")
          {
            type_=CommandType::MAP;
          }
            else if (command == "QUIT")
            {
              type_=CommandType::QUIT;
            }
              else type_=CommandType::INVALID;
  size_t s=std::size(input);
  for (size_t i=1; i<s; ++i)
  {
    parameters_.push_back(input[i]);
  }
}