#pragma one
#include "Trie.h"

Trie::Trie() {
	root = new Node();
}

Node* Trie::getRoot() {
	return this->root;
}

void Trie::insert(string newKey) {
	Node* tmp = root;
	for (int i = 0; i < newKey.size(); i++) {
		int ascii = newKey[i] - 'a';
		if (tmp->children[ascii] != nullptr)
			tmp = tmp->children[ascii];
		else {
			tmp->children[ascii] = new Node();
			tmp = tmp->children[ascii];
			tmp->character = newKey[i];
		}
	}
	tmp->endOfWord = 1;
}

void Trie::traversalTree(Node* root, string& data, string& currentString, vector<string>& wordList, int dataLength) {
	Node* current = root;

	if (current->isWord() == 1 && currentString.size() >= 3) {
		wordList.push_back(currentString);
		if (currentString.size() == dataLength) return;
	}

	for (int i = 0; i < 26; i++) {
		if (current->children[i] != nullptr && data.find(current->children[i]->character) != -1) {
			char currentWord = current->children[i]->character;
			currentString += currentWord;
			data.erase(data.find(currentWord), 1);
			(*this).traversalTree(current->children[i], data, currentString, wordList, dataLength);
			currentString.pop_back();
			data += currentWord;
		}
	}

}