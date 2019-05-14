#include <iostream>
#include <assert.h>

#include "UserInfo.cpp"
#include "Trie.h"


int main()
{
    UserInfo user1("user", "123");
    assert(user1.getName() == "user");
    assert(user1.getPassword() == "123");

    Trie t;
    t.insert(user1.getName());
}
