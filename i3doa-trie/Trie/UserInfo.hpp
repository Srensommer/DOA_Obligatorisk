#ifndef USERINFO
#define USERINFO

#include <string>

class UserInfo{
    private:
        std::string name_;
        std::string password_;
        int highscore_;
    public:
        UserInfo(std::string, std::string);
        std::string getName() const;
        bool validate(std::string) const;
        int getHighscore() const;
        void setHighscore(int);
};

#endif
