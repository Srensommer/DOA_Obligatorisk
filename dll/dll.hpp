#ifndef _DLL_HEAD_
#define _DLL_HEAD_

#include <iostream>
#include <string>
#include "UserInfo.hpp"


class Node
{
    public:
        Node();
        int highscore;
        std::string username;
        Node *next;
        Node *prev;
    private:
        char password;
};

class DLL
{
public:
	DLL();
    
    void print_head();                      // print node with highest highscore

	void push(UserInfo *node); // Add new node to head, no sort

    void insert_before(UserInfo *node, UserInfo *compare);
    void insert_last(UserInfo *node, UserInfo *compare);
	void print();                           // print all names and highscores 
    void print_byName(std::string name);    // print specific node


	void insert_sort(UserInfo *node); // Insert node sorted by highscore
	void insertionSort();                           // Insertion sort algorithm, use if list is not sorted
	
    //void remove_node(const DLL &);
	//void update_score(char user_name);

	~DLL();

private:
	UserInfo *head;
	UserInfo *tail;
	int length;
};


#endif // _DLL_HEAD_





