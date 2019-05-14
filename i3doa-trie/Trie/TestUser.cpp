#include <assert.h>

#include "UserInfo.hpp"


int main()
{
    UserInfo user("bob", "password");
    user.setHighscore(2000);

    assert(user.getHighscore() == 2000);
    assert(user.getName() == "bob");
    assert(user.validate("password") == true);
}
