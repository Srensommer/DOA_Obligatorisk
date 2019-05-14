#include "test_dll.hpp"

void test()
{
	std::cout << "hello" << std::endl;

	DLL dll;

    UserInfo user1("bob", "password");
    user1.setHighscore(200);

    UserInfo user2("marg", "abc");
    user2.setHighscore(420);

    UserInfo user3("dog", "goodboi");
    user3.setHighscore(220);


    // test insert sorted
	std::cout << "=== INSERT SORTED ===" << std::endl; 
    dll.insert_sort(&user1);
    dll.insert_sort(&user2);
    dll.insert_sort(&user3);

    // print all highscores
    std::cout << "=== Print Score Sorted ===" << std::endl; 
	dll.print();


    // Find name based on score
    std::cout << "=== FIND NAME ===" << std::endl; 
    dll.print_byName("marg");
    dll.print_byName("bob");


    // Print biggest score
    std::cout << "=== Highest highscore ===" << std::endl; 
    dll.print_head();



    // Opdater score
    std::cout << "=== Update Highscore ===" << std::endl;
    


    std::cout << "==================================" << std::endl; 


}

