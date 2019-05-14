#ifndef USERINFO
#define USERINFO

#include <string>
#include <vector>

#include "GameInfo.cpp"


class UserInfo{
    private:
        std::string name_;
        std::string password_;
        int highscore_;
        std::vector<GameInfo> games_;
    public:
        UserInfo(std::string, std::string);
        std::string getName() const;
        std::string getPassword() const;
        int getHighscore() const;
        std::vector<GameInfo>::const_iterator getGames() const;
};

#endif
