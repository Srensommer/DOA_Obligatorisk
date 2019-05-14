#include <assert.h>

#include "UserInfo.hpp"
#include "Trie.h"

int main()
{
    //Opret en bruger og test at alle parametre er som antaget
    UserInfo user("bob", "password");
    user.setHighscore(2000);

    assert(user.getHighscore() == 2000);
    assert(user.getName() == "bob");
    assert(user.validate("password") == true);

    //Test Trie
    Trie t;
    t.insert("john1", new UserInfo("john1", "fedeabe"));
    t.insert("john2", new UserInfo("john2", "abefed"));

    assert(t.search("john1") != nullptr);
    assert(t.search("john3") == nullptr);

    UserInfo* user1 = t.search("john1");
    t.remove("john1");
    delete user1;

    assert(t.search("john1") == nullptr);
}
