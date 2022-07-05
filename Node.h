#pragma once
#pragma once
#include "Trie.h"

// Create the class node, every trie node will have this data type
class Node
{
	// Class Trie can access the private variables as well as methods of class Node
	friend class Trie;
public:
	// VARIABLES
	// Insstead of storing each character in a path, store in a node 
	char character;
	bool endOfWord; // If there is a key end at this node
	// Its children 
	Node* children[26]; 

	// METHODS
	Node();
	~Node() {}

	void setEndOfWord(bool isEnd);
	void setCharacter(char c);
	bool isWord();
};