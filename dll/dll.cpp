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

void DLL::push(UserInfo *node)
{
    node->next = head;
    node->prev = nullptr;

    if (head != nullptr)
        head->prev = node;

    head = node;
    length++;
}

void DLL::insert_last(UserInfo *node)
{
    node->prev = tail;
    node->next = nullptr;

    if (tail != nullptr)
        tail->next = node;

    tail = node;
    length++;
}


void DLL::insert_sort(UserInfo *node)
{
    int inserted = 0;


    UserInfo *compare = head;

    if(node->getHighscore() > head->getHighscore())
        push(node);

    compare = compare->next;

    while(compare)
    {
        if(node->getHighscore() > compare->getHighscore())
        {
            insert_before(node, compare);
            inserted = 1;
        }

        compare = compare->next;
    }

    if(inserted == 0)
    {
       insert_last(node);
    }
}


void DLL::insert_before(UserInfo *node, UserInfo *compare)
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


void DLL::print()
{
	UserInfo *node = head;

	while (node)
	{
		std::cout << "Node " << node->getName() << ": " << node->getHighscore() << std::endl;
		node = node->next;
	}

}

void DLL::print_head()
{
    std::cout << "Head: " << head->getName() << " " << head->getHighscore() << std::endl;
}


void DLL::print_byName(std::string name)
{
    int found = 1;

    UserInfo *node = head;

    while(node)
    {
        if(node->getName().compare(name) == 0)
        {
		    std::cout << "Node " << node->getName() << ": " << node->getHighscore() << std::endl;
            found = 0;
        }
        node = node->next;
    }

    if(found == 1)
    {
        std::cout << "Cannot find node" << std::endl;
    }
}


/*
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
*/


void DLL::remove_node(UserInfo *node)
{
    if(head == nullptr || node == nullptr)
        return;

    if(node == head)
        head = node->next;

    if(node->next != nullptr)
        node->next->prev = node->prev;

    if(node->prev != nullptr)
        node->prev->next = node->next;
 
    delete(node);
}


void DLL::update_score(UserInfo *node, int score, std::string password)
{
    if(node->getHighscore() > score) // Old score is greater
        return;

    if(node->validate(password) == false)
        return;

    UserInfo new_node(node->getName(), password);
    new_node.setHighscore(score);

    remove_node(node);
    insert_sort(&new_node);
}
