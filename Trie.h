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

	void traversalTree(Node* Root, string& Data, string& CurrentString, vector<string>& WordList, int DataLength);
};
