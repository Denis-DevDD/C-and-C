#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>

class Command
{
  public:
    enum class CommandType
    {
      PLACE, PASS, MOVE, MAP, INFO, QUIT, INVALID, WRONG_PARAM
    };
  private:
    CommandType type_;
    std::vector<std::string> parameters_;
  public:
    Command(std::vector<std::string>& input);
    Command(CommandType type) : type_{type}{}
    bool isQuit();
    CommandType getType() const;
    std::vector<std::string>& getParameters();
    void setType(CommandType type);
    ~Command()=default;
};

#endif