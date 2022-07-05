#include "Node.h"

Node::Node()
{
	this->setCharacter('\0');
	this->setEndOfWord(false);

	for (int i = 0; i < 26; i++)
	{
		this->children[i] = nullptr;
	}
}
void Node::setEndOfWord(bool isEnd)
{
	this->endOfWord = isEnd;
}

void Node::setCharacter(char c)
{
	this->character = c;
}

bool Node::isWord()
{
	return this->endOfWord;
}