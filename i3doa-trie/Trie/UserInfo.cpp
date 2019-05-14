#include "UserInfo.hpp"


UserInfo::UserInfo(std::string name, std::string password)
:name_(name), password_(password), highscore_(0){}


std::string UserInfo::getName() const
{
    return name_;
}

bool UserInfo::validate(std::string password) const
{
    if(password_.compare(password) == 0)
    {
        return true;
    }
    return false;
}

int UserInfo::getHighscore() const
{
    return highscore_;
}

void UserInfo::setHighscore(int highscore)
{
    highscore_ = highscore;
}
