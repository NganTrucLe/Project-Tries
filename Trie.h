#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
using namespace std;

class Trie
{
	friend class Node;
private:
	Node* root;
public:
	Trie();
	~Trie() {}

	Node* getRoot();

	void insert(string data);

	void traversalTree(Node* root, string& data, string& currentString, vector<string>& wordList, int dataLength);
};
