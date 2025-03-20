#include <iostream>
#include "Command.hpp"
#include "CommandLine.hpp"

void CommandLine::removeTrailingWhitespaces(std::string &string)
{
  size_t end = string.find_last_not_of(' ');
  string = end == std::string::npos ? "" : string.substr(0, end + 1);
}

void CommandLine::removeLeadingWhitespace(std::string &string)
{
  auto start = string.find_first_not_of(' ');
  string = start == std::string::npos ? "" : string.substr(start);
}

void CommandLine::removeWhitespacesAtEnds(std::string &string)
{
  removeLeadingWhitespace(string);
  removeTrailingWhitespaces(string);
}

void CommandLine::stringToVector(const std::string &string, std::vector<std::string> &vector, char delimiter)
{
  size_t position = 0;
  size_t position2;
  std::string split_word;
  while ((position2 = string.find(delimiter, position)) != std::string::npos)
  {
    split_word = string.substr(position, position2 - position);
    position = position2 + 1;
    removeWhitespacesAtEnds(split_word);
    if (!split_word.empty())
    {
      vector.push_back(split_word);
    }
  }
  vector.push_back(string.substr(position));
}

Command CommandLine::readCommand()
{
  std::cout << " > ";
  std::string input;
  std::getline(std::cin, input);
  removeWhitespacesAtEnds(input);
  if (input.empty())
  {
    return Command(Command::CommandType::INVALID);
  }
  std::vector<std::string> vectorised_string;
  stringToVector(input, vectorised_string, ' ');
  Command command(vectorised_string);
  switch (command.getType())
  {
    case Command::CommandType::QUIT:
      if (!command.getParameters().empty())
      {
        command.setType(Command::CommandType::WRONG_PARAM);
      }
      break;
    case Command::CommandType::INVALID:
      std::cout << "[ERROR] Entered command not found!" << std::endl;
      return command;
    case Command::CommandType::PASS:
    case Command::CommandType::MAP:
    case Command::CommandType::INFO:
      if (!command.getParameters().empty())
      {
        command.setType(Command::CommandType::WRONG_PARAM);
      }
      break;
    case Command::CommandType::PLACE:
      if (command.getParameters().size() != 3)
      {
        command.setType(Command::CommandType::WRONG_PARAM);
      }
      break;
    case Command::CommandType::MOVE:
      if (command.getParameters().size() != 5)
      {
        command.setType(Command::CommandType::WRONG_PARAM);
      }
      break;
    case Command::CommandType::WRONG_PARAM:
      break;
  }
  if (command.getType() == Command::CommandType::WRONG_PARAM)
  {
    std::cout << "[ERROR] Wrong number of parameters for this command!" << std::endl;
  }
  return command;
}
