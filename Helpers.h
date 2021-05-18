#ifndef _HELPERS_
#define _HELPERS_

#include "TrieNode.h"
#include <fstream>

/**
Helper function to read the dictionary.txt file into a string.
@param dictionary_string The string to store dictionary.txt.
*/
void read_dictionary_into_string(std::string dictionary_string);

/**
Helper function to read the dictionary.txt file into a trie.
@param dictionary_trie The trie to store dictionary.txt.
*/
void read_dictionary_into_trie(Trie dictionary_trie);

#endif