#ifndef _DLL_HEAD_
#define _DLL_HEAD_

#include <iostream>
#include <string>

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

	void push(int data, std::string name);  // Add new node to head, no sort
    void insert_before(Node *node, Node *compare);
    void insert_last(Node *node, Node *compare);
	void print();                           // print all names and highscores 
    void print_byName(std::string name);    // print specific node

	void insert_sort(int data, std::string name);   // Insert node sorted by highscore
	void insertionSort();                           // Insertion sort algorithm, use if list is not sorted
    void test(Node *test);
	
    //void remove_node(const DLL &);
	//void update_score(char user_name);

	~DLL();

private:
	Node *head;
	Node *tail;
	int length;
};

/*
class Node
{
public:
	Node(int score, Node *n = nullptr, Node *p = nullptr) : highscore(score), next(n), prev(p) {}
	int highscore;
	//char userName = "";
	Node *next;
	Node *prev;
private:
	//char password = "";
};
*/

#endif // _DLL_HEAD_





