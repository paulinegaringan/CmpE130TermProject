#ifndef _TRIE_
#define _TRIE_

#include <iostream>
#include <memory>
#include <map>

/**
A trie container implemented as a prefix tree.
Note that since we use smart pointers, we didn't create a destructor.
*/
class Trie {
private:
	// TrieNode as nested struct.
	struct TrieNode;

	// Root for the prefix tree.
	std::shared_ptr<TrieNode> root;
public:
	/**
	Default constructor. Creates a new TrieNode on the root.
	*/
	Trie();

	/**
	Inserts a string into the trie. It adds any string, including duplicates.
	@param word The word to be added into the string.
	*/
	void insert(std::string word);

	/**
	Searchs for a given prefix. Does this by checking the last matching node's
	prefixes counter.
	@param word The number of prefixes found.
	*/
	size_t count_shared_prefixes(std::string word);

	/**
	Searchs for a specific word within the trie. Does this by checking the last
	matching node's end_of_word flag.
	@param word The word being searched.
	@return Wether the word was found or not.
	*/
	bool search_algorithm(std::string word);

	/**
	Helper function for search_algorithm().
	Prompts for a word, searchs it, and prints whether it was found or not.
	*/
	void search();
};

#endif