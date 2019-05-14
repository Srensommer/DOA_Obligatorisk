#include "UserInfo.hpp"


UserInfo::UserInfo(std::string name, std::string password)
:name_(name), password_(password){}


std::string UserInfo::getName() const
{
    return name_;
}


std::string UserInfo::getPassword() const
{
    return password_;
}

 
int UserInfo::getHighscore() const
{
    return highscore_;
}

std::vector<GameInfo>::const_iterator UserInfo::getGames() const
{
    return games_.begin();
}
