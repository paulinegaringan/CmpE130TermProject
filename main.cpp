#include "Helpers.h"
#include "StringAlgorithms.h"
#include <chrono>

const std::string to_search[] = { "apple", "banana", "coconut", "date",
	 "elderberry", "fig", "grape", "hackberry", "imbe", "jackfruit", "kiwi",
	 "lime", "mango", "nectarine", "orange", "papaya", "quesadilla", "rambutan",
	 "strawberry", "tangerine", "ugli", "vanilla", "watermelon", "xray",
	 "yellow", "zucchini" };

int main() {
   // Search in the Trie structure.
   std::cout << "TRIE:\n";
   Trie trie;
	read_dictionary_into_trie(trie);
	double duration;
   for (size_t i = 0; i < 26; ++i) {
      auto start = std::chrono::high_resolution_clock::now();
      trie.search_algorithm(to_search[i]);
      auto stop = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::nanoseconds>
         (stop - start).count();
      std::cout << to_search[i] << "'s search time:\t\t" << duration << '\n';
   }

   // Search using the Boyer-Moore algorithm.
   std::cout << "\nBOYER-MOORE:\n";
	std::string dictionary;
	read_dictionary_into_string(dictionary);
	for (size_t i = 0; i < 26; ++i) {
     auto start = std::chrono::high_resolution_clock::now();
	  boyerMooreSearch(dictionary, to_search[i]);
     auto stop = std::chrono::high_resolution_clock::now();
     duration = std::chrono::duration_cast<std::chrono::nanoseconds>
        (stop - start).count();
     std::cout << to_search[i] << "'s search time:\t\t" << duration << '\n';
  }
   
   //Search using the Brute Force algorithm.
   std::cout << "\nBRUTE FORCE:\n";
   for (size_t i = 0; i < 26; ++i) {
      auto start = std::chrono::high_resolution_clock::now();
      bruteForceSearch(dictionary, to_search[i]);
      auto stop = std::chrono::high_resolution_clock::now();
      duration = std::chrono::duration_cast<std::chrono::nanoseconds>
         (stop - start).count();
      std::cout << to_search[i] << "'s search time:\t\t" << duration << '\n';

   }
}
