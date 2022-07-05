#include <iostream>
#include <fstream>
#include <vector>
#include "Trie.h"
#include "Node.h"

#define vi vector<string> 

string inputFile(string fileName) {
    string word;
    ifstream fi;
    fi.open(fileName);
    if (!fi.is_open()) {
        cout << "Error! Cannot open file.\n";
        return word;
    }
    while (!fi.eof()) {
        string tmp;
        fi >> tmp;
        word.append(tmp);
    }
    fi.close();
    return word;
}
Trie buildTrieFromDic(string fileName) {
    ifstream fi;
    fi.open(fileName);
    Trie newTrie;
    if (!fi.is_open()) {
        cout << "Error! Cannot open file.\n";
        return newTrie;
    }
    string word;
    while (!fi.eof()) {
        fi >> word;
        newTrie.insert(word);
    }
    fi.close();
    return newTrie;
}
vi generateWordList(Trie tree, string data) {
    vi wordList;
    string currentString;
    tree.traversalTree(tree.getRoot(), data, currentString, wordList, data.size());
    return wordList;
}
void outputFile(string fileName, vi wordList) {
    ofstream fo;
    fo.open(fileName);
    if (!fo.is_open()) {
        cout << "Error!Cannot open file.\n";
        return;
    }
    fo << wordList.size() << endl;
    for (int i = 0; i < wordList.size(); i++)
        fo << wordList[i] << endl;
    fo.close();
}
int main()
{
    Trie myTrie = buildTrieFromDic("Dic.txt");
    string characterList = inputFile("input.txt");
    vi result = generateWordList(myTrie, characterList);
    outputFile("output.txt", result);
    return 0;
}
