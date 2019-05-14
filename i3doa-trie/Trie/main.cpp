#include <iostream>
#include <assert.h>

#include "UserInfo.hpp"
#include "Trie.h"


int main()
{
    UserInfo* user1 = new UserInfo("user", "123");
    assert(user1->getName() == "user");

    Trie t;
    t.insert(user1->getName(), user1);

    UserInfo* foundUser = t.search(user1->getName());

    assert(foundUser->validate("123"));
}
