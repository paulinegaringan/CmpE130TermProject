#ifndef _TRIENODE_
#define _TRIENODE_

#include "Trie.h"

/**
A TrieNode class for our trie structure.
*/
struct Trie::TrieNode {
	// Befriend Trie so it can use TrieNode's components.
	friend Trie;

private:
	std::map<char, std::shared_ptr<TrieNode>> children;
	size_t prefixes;
	bool end_of_word;
	TrieNode();
};

#endif