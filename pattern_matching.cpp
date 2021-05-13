#include <iostream>
#include <string>
#define numOfChars 512
using namespace std;

bool bruteForceSearch(string text, string pattern);
int badCharacterRule(string pattern, int size, int badchar);
int boyerMooreSearch(string text, string pattern);
void computeLPSArray(string pattern, int p, int lps);
void KMPSearch(string text, string pattern);

/*Brute Force Algorithm - referenced from ProDeveloperTutorial.com*/
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
/***********************************************************************************/
/*Boyer-Moore Algorithm - referenced from GeekforGeeks*/
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int badCharacterRule(string pattern, int size, int badchar[numOfChars])
{
    int i;
    for (i = 0; i < numOfChars; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int)pattern[i]] = i;
}

int boyerMooreSearch(string text, string pattern)
{
    int t = text.length();
    int p = pattern.length();
    int badchar[numOfChars];
    badCharacterRule(pattern, p, badchar);
    int shift = 0;
    while (shift <= (p - t))
    {
        int j = p - 1;
        while (j >= 0 && pattern[j] == text[shift + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "Found pattern at shift " << shift << endl;
            if ((shift = shift + (shift + p)) < t)
                p - badchar[text[shift + p]];
            else
                return 1;
        }
        else
            shift = shift + max(1, j - badchar[text[shift + j]]);
    }
}
/***********************************************************************************/
/*KMP Algorithm -  referenced from GeekforGeeks*/
void computeLPSArray(string *pat, int p, int *lps)
{
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < p)
    {
        if (pat[i] == pat[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern)
{
    int t = text.length();
    int p = pattern.length();
    int lps[numOfChars];

    computeLPSArray(pattern, p, lps[numOfChars]);

    int i = 0; //text index
    int j = 0; //pattern index

    while (i < t)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == p)
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < p && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

/*Main function to test each algorithm - */
int main()
{
    //string txt;
    //string pattern;
    //cout << "Please enter some text: ";
    //getline(cin, txt);
    //cout << "Please enter a pattern: ";
    //getline(cin, pattern);

    string text = "AACGTACAATTGGA";
    cout << "Text: " << text << endl;
    string pattern = "TACA";
    cout << "Pattern: " << pattern << endl;
    bruteForceSearch(text, pattern);
    cout << "Pattern " << pattern << "Found!";
    boyerMooreSearch(text, pattern);
    cout << "Pattern " << pattern << "Found!";
    KMPSearch(text, pattern);
    cout << "Pattern " << pattern << "Found!";
    system("pause");
    return 0;
}
