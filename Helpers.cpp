#include "Helpers.h"

void read_dictionary_into_string(std::string dictionary_string) {
	// Open dictionary.txt.
	std::ifstream dictionary_file("dictionary.txt");
	// Open the dictionary and check for errors.
	if (!dictionary_file.is_open()) {
		std::cout << "Error. Can't open dictionary.txt.";
		return;
	}
	std::string word;
	// Iterate over the words in the dictionary.
	while (dictionary_file >> word) {
		// Inserting words into the dictionary string.
		dictionary_string += word;
	}
	// Close dictionary.txt.
	dictionary_file.close();
}

void read_dictionary_into_trie(Trie dictionary_trie) {
	// Open dictionary.txt.
	std::ifstream dictionary_file("dictionary.txt");
	// Open the dictionary and check for errors.
	if (!dictionary_file.is_open()) {
		std::cout << "Error. Can't open dictionary.txt.";
		return;
	}
	std::string word;
	// Iterate over the words in the dictionary.
	while (dictionary_file >> word) {
		// Inserting words into the dictionary trie.
		dictionary_trie.insert(word);
	}
	// Close dictionary.txt.
	dictionary_file.close();
}