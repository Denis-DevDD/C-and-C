#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
  private:
    char id_;
    int chips_{0};
    bool has_passed_{false};
  public:
    Player(char id);
    char getID() const;
    int getChips() const;
    void setPass(bool pass);
    void setChips(int chip);
    bool getPass() const;
    ~Player();
};

#endif