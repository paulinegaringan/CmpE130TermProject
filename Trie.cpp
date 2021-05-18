#include "TrieNode.h"

Trie::Trie() : root(new TrieNode) { }

void Trie::insert(std::string word) {
	std::shared_ptr<TrieNode> curr_node = root;
	// Iterate over the Trie.
	for (size_t i = 0; i < word.size(); ++i) {
		// If the current node has no child mapping to the current character.
		if (!curr_node->children[word[i]]) {
			// Create a child node mapping to the current character.
			curr_node->children[word[i]].reset(new TrieNode);
		}
		std::map<char, std::shared_ptr<TrieNode>> children;
		// Since a new word was added, increase the node's prefix count.
		++curr_node->prefixes;
		// Continue the iteration.
		curr_node = curr_node->children[word[i]];
	}
	// Activate the node's flag indicating the end of a word.
	curr_node->end_of_word = true;
}

size_t Trie::count_shared_prefixes(std::string word) {
	std::shared_ptr<TrieNode> curr_node = root;
	// Iterate over the Trie.
	for (size_t i = 0; i < word.size(); ++i) {
		// If the current node has no child mapping to the current character.
		if (!curr_node->children[word[i]]) {
			return 0;
		}
		// Continue the iteration.
		curr_node = curr_node->children[word[i]];
	}
	// Retrieve and return the number of prefixes on the current node.
	return curr_node->prefixes;
}

bool Trie::search_algorithm(std::string word) {
	std::shared_ptr<TrieNode> curr_node = root;
	// Iterate over the Trie.
	for (size_t i = 0; i < word.size(); ++i) {
		// If the current node has no child mapping to the current character.
		if (!curr_node->children[word[i]]) {
			return false;
		}
		// Continue the iteration.
		curr_node = curr_node->children[word[i]];
	}
	// Return whether the current node marks the end of a word or not.
	return curr_node->end_of_word;
}

void Trie::search() {
	std::string prefix_input;
	std::cout << "Search a prefix: ";
	std::cin >> prefix_input;
	// Print whether the word was found or not.
	search_algorithm(prefix_input)? std::cout << "Found!\n" : 
		std::cout << "Not found!\n";
}