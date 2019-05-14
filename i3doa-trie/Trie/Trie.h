#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>


#include "UserInfo.hpp"


using namespace std;

class Trie
{
	class TrieNode;

	typedef map<char, TrieNode*> TrieMap;
	typedef map<char, TrieNode*>::iterator TrieMapIter;

	// Internal TrieNode class - not relevant outside Trie
	class TrieNode
	{
	public:
		TrieNode(char c = '\0', bool cw = false, TrieNode* p = nullptr) :
			val(c), parent(p), completesWord(cw), user(nullptr)
		{
			children.clear();
		}
		char val;
		TrieNode* parent;
		bool completesWord;
        UserInfo* user;
		TrieMap children;
	};



public:
	Trie()
	{
		root = new TrieNode('\0', true);
	}


	~Trie()
	{
		delete root;
	}


	void insert(string str, UserInfo* user)
	{
		TrieNode *cur = root;
		TrieMapIter res;
		
		//Iterates trough each letter in the given string 
		for (int i = 0; i < str.length(); i++) 
		{
			//If the letter exsists in children, set cursor to child
			if ((res = cur->children.find(str[i])) != cur->children.end()) 
			{
				cur = res->second;
			}
			else 
			{
				TrieNode *n;
				if (i == str.length() - 1) 
				{
					n = new TrieNode(str[i], true);
					n->parent = cur;
				}
				else 
				{
					n = new TrieNode(str[i], false);
					n->parent = cur;
				}
				cur->children.insert(std::pair<char, TrieNode*>(str[i], n));
				cur = n;
				printf("ADD %c\n", str[i]);
			}
            cur->user = user;
		}
        cur->completesWord = true;
	}

	UserInfo* search(string str) const
	{
		TrieNode *cur = root;
		TrieMapIter res;

		for (int i = 0; i < str.length(); i++) {
			if ((res = cur->children.find(str[i])) != cur->children.end()) {
				cur = res->second;
				cout << "Found" << str[i] << endl;
			}
            else
            {
                return nullptr;
            }
			if (cur->completesWord && i == str.length() - 1) return cur->user;
		}
		return nullptr;
	}

	//Denne metode har samme problem som search.. Den gør ikke brug af findPrefixEnd, og den skulle angiveligt være mega smarts.
	void remove(string str) const
	{
		TrieNode *cur = root;
		TrieMapIter res;

		for (int i = 0; i < str.length(); i++) {

			if ((res = cur->children.find(str[i])) != cur->children.end()) {
				cur = res->second;
			}
		}
        cur->completesWord = false;
        cur->user = nullptr;
        std::cout << "found word to remove: " << cur->val <<  std::endl;

        //Dealokates unused nodes.
        std::cout << "entries in parrent"  << cur->parent->children.size() << std::endl;

        while(cur->children.size() == 0 && !cur->completesWord)
        {
            TrieNode* parent = cur->parent;

            //empties map with only one child
            parent->children.erase(cur->val);
            std::cout << "Removes " << cur->val << std::endl;
            delete cur;
            cur = parent;
            parent = cur->parent;
        }

	}

	void findAllWithPrefix(string prefix, vector<string>& strings) const
    	{
		// We don't need this.. But maybe smartz...
		//Confirmed smartz.. we need this..  RIP Søren "Karl Kode" Sommer's implementation
	}


private:
	// findPrefixEnd: 
	// Sets the parameter end to the last node in the prefix of str and returns the length of the prefix
	unsigned int findPrefixEnd(string str, TrieNode*& end) const
	{
		TrieNode* cur = root;
		TrieMapIter res;
		unsigned int i = 0;

		// Find (part of) key already in trie
		for (; i < str.length(); i++)
		{
			if ((res = cur->children.find(str[i])) != cur->children.end())
			{
				cur = res->second;
			}
			else break;
		}
		end = cur;
		return i;
	}


	TrieNode* root;
};
