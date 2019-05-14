#include "dll.hpp"


int main()
{
	std::cout << "hello" << std::endl;

	DLL dll;
	
    dll.push(1, "en");
    dll.push(2, "to");
    dll.push(3, "tre");

	dll.print();



    dll.print_byName("en");
    dll.print_byName("tre");


    dll.print_head();



	return 0;
}

