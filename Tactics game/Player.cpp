#include "Player.hpp"
#include <iostream>
#include <vector>

Player::Player(char id)
{
  id_=id;
}
char Player::getID() const
{
  return id_;
}
int Player::getChips() const
{
  return chips_;
}
void Player::setPass(bool pass)
{
  has_passed_=pass;
}
void Player::setChips(int chip)
{
  chips_=chip;
}
bool Player::getPass() const
{
  return has_passed_;
}
Player::~Player()=default;