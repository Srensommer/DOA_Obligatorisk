#include "dll.hpp"

DLL::DLL()
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

DLL::~DLL()
{

}

Node::Node()
{
	highscore = 0;
    username = ' ';
	next = nullptr;
	prev = nullptr;
}

void DLL::push(int data, std::string name)
{
	Node *node = new Node();
	node->highscore = data;
    node->username = name;
	
	node->next = head;
	node->prev = nullptr;

	if (head != nullptr)
		head->prev = node;

	head = node;
	length++;
}


void DLL::insert_sort(int data, std::string name)
{
    int inserted = 0;
    Node *node = new Node();
    node->highscore = data;
    node->username = name;


    Node *compare = head;

    while(compare)
    {
        if(node->highscore > compare->highscore)
        {
            insert_before(node, compare);
            inserted = 1;
        }

        compare = compare->next;
    }

    if(inserted == 0)
    {
       // insert last 
    }


}

void DLL::insert_before(Node *node, Node *compare)
{
    if(compare == nullptr)
    {
       return; 
    }

    node->prev = compare->prev;
    compare->prev = node;

    node->next = compare;

    if(node->prev != nullptr)
        node->prev->next = node;
    else
        head = node;
}

void DLL::insert_last(Node *node, Node *compare)
{

}

void DLL::print()
{
	Node *node = head;

	while (node)
	{
		std::cout << "Node " << node->username << ": " << node->highscore << std::endl;
		node = node->next;
	}

}

void DLL::print_head()
{
    std::cout << "Head: " << head->username << std::endl;
}


void DLL::print_byName(std::string name)
{
    int found = 1;

    Node *node = head;

    while(node)
    {
        if(node->username.compare(name) == 0)
        {
		    std::cout << "Node " << node->username << ": " << node->highscore << std::endl;
            found = 0;
        }
        node = node->next;
    }

    if(found == 1)
    {
        std::cout << "Cannot find node" << std::endl;
    }
}

void DLL::insertionSort()
{
    int i, j;
    int score;
    int arr[10];

    for(i = 1; i < length; i ++)
    {
        score = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > score)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = score;

    }

}


