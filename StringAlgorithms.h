#ifndef _STRING_ALGORITHMS_
#define _STRING_ALGORITHMS_

#include <iostream>
#include <string>

#define numOfChars 256

void bruteForceSearch(std::string text, std::string pattern);
void badCharacterRule(std::string pattern, int size, int badchar);
void boyerMooreSearch(std::string text, std::string pattern);

#endif