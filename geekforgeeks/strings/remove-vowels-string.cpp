#include <bits/stdc++.h>

using namespace std;

void removeVowels(string str)
{
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                           'A', 'E', 'I', 'O', 'U'};

    string s;
    for (auto c : str)
    {
        auto it = find(vowels.begin(), vowels.end(), c);
        // if it == vowels.end() then it is not a vowel and we will push it into the new string
        if (it == vowels.end())
        {
            s.push_back(c);
        }
    }

    cout << s;
}

void remVowel(string str)
{
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                           'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < str.length(); i++)
    {
        if (find(vowels.begin(), vowels.end(),
                 str[i]) != vowels.end())
        {
            str = str.replace(i, 1, "");
            i -= 2;
        }
    }
    cout << str;
}

int main(int argc, char const *argv[])
{
    string str = "welcome to geeksforgeeks";
    remVowel(str);

    return 0;
}