#include "dll.hpp"


int main()
{
	std::cout << "hello" << std::endl;

	DLL dll;

    UserInfo user1("bob", "password");
    user1.setHighscore(100);


    UserInfo user2("marg", "abc");
    user2.setHighscore(120);

    UserInfo user3("dog", "goodboi");
    user3.setHighscore(220);

	
    dll.push(&user1);
    dll.push(&user2);
    dll.push(&user3);

	dll.print();



    dll.print_byName("en");
    dll.print_byName("bob");


    dll.print_head();



	return 0;
}

