#include <bits/stdc++.h>
using namespace std;

/*
    1. Calculate LPS[] array for the pattern
*/

void LPS(string &ptr, vector<int> &lps)
{
    int m = ptr.length();
    int len = 0;

    lps[0] = 0; // LPS[0] is always 0
    int i = 1;  // Start from the second character

    while (i < m)
    {
        if (ptr[i] == ptr[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string &str, string &ptr)
{
    int n = str.length();
    int m = ptr.length();

    vector<int> lps(m, 0);
    LPS(ptr, lps);

    int i = 0; // Pointer for text
    int j = 0; // Pointer for pattern
    vector<int> result;

    while (i < n)
    {
        if (ptr[j] == str[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            result.push_back(i - j + 1); // Pattern found, 1-based indexing
            j = lps[j - 1];
        }
        else if (i < n && ptr[j] != str[i])
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

    if (result.size() > 0)
    {
        for (auto it : result)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}

int main()
{
    string str, pattern;
    cin >> str >> pattern;
    KMP(str, pattern);
    return 0;
}
