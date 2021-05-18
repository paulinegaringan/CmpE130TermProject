#include "StringAlgorithms.h"

void bruteForceSearch(std::string text, std::string pattern)
{
	int t = text.length(); //define the length of the text
	int p = pattern.length(); //define the length of the pattern

	//goes through each element of the test
	for (int i = 0; i <= t - p; i++)
	{
		int j;
		//compares the current elements i and j
		for (j = 0; j < p; j++)
		{
			//returns nothing when no match is found
			if (text[i + j] != pattern[j])
				break;
		}
		//pattern matches the text
		if (j == p)
			std::cout << "Brute Force found the pattern " << pattern << '\n';
	}
}
/***********************************************************************************/
/*Boyer-Moore Algorithm - referenced from GeekforGeeks*/
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
//creates the bad character table which dictates how the characters should be shifted
void badCharacterRule(std::string pattern, int size, int badchar[numOfChars])
{
	int i;
	for (i = 0; i < numOfChars; i++)
	{
		badchar[i] = -1;
	}
	for (i = 0; i < size; i++)
	{
		badchar[(int)pattern[i]] = i;
	}
}
//String matching algorithm - Boyer-Moore with Bad Character Rule
void boyerMooreSearch(std::string text, std::string pattern)
{
	int t = text.length(); //define the length of the text
	int p = pattern.length(); //define the length of the pattern
	int badchar[numOfChars]; //defines the number of characters the bad character table can hold
	badCharacterRule(pattern, p, badchar);
	int shift = 0; //initializes the amount of shifts being made wrt the text
	while (shift <= (t - p))
	{
		int j = p - 1; //initizalzes the index to be smaller than the length of the pattern
		while (j >= 0 && pattern[j] == text[shift + j])
		{
			j--;
		}
		//if the patterns appears in the text, we find where the pattern happens
		if (j < 0)
		{
			std::cout << "Boyer-Moore found the pattern " << pattern << '\n';
			//std::cout << "Pattern appears at shift " << shift << '\n';
			//shifts the characters until the mismatch character finds a match or completely shift past the mismatch
			if (shift + (shift + p) < t)
				shift = p - badchar[text[shift + p]];
			else
				shift = 1;
			break;
		}
		//if a match is not found it should return nothing
		else
			//shift the characters completely - finding no pattern
			shift = shift + max(1, j - badchar[text[shift + j]]);
		//std::cout << "Boyer-Moore did NOT find the pattern " << pattern << '\n';
	}
}