#include <iostream>
#include <string>

using namespace std;

/*Brute Force Algorithm - referenced ProDeveloperTutorial.com*/
bool bruteForceSearch(string text, string pattern)
{
    int t = text.length();
    int p = pattern.length();

    for (int i = 0; i <= t - p; i++)
    {
        int j;
        for (j = 0; j < p; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == p)
            return true;
    }
    return false;
}
/*Boyer-Moore Algorithm - */
void boyerMooreSearch(string text, string pattern)
{
    int t = text.length();
    int p = pattern.length();
}
/*KMP Algorithm - */
void KMPSearch(string text, string pattern)
{
    int t = text.length();
    int p = pattern.length();
}
/*Main function to test each algorithm - */
int main()
{
}
