#include <bits/stdc++.h>

using namespace std;

class SolutionUsingRecursion
{
public:
    void getAllLetters(int start, string word, unordered_map<char, string> phoneMap, string digits, vector<string> &ans)
    {

        if (start == digits.size())
        {
            ans.push_back(word);
            return;
        }

        string letters = phoneMap[digits[start]];

        for (auto letter : letters)
        {
            word += letter;
            getAllLetters(start + 1, word, phoneMap, digits, ans);
            word.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits == "")
        {
            return ans;
        }

        unordered_map<char, string> phoneMap =
            {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"},
            };

        string word = "";

        getAllLetters(0, word, phoneMap, digits, ans);

        return ans;
    }
};

class SolutionIterative
{
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> result;
        result.push_back("");

        for (auto digit : digits)
        {
            vector<string> tmp;
            for (auto candidate : pad[digit - '0'])
            {
                for (auto s : result)
                {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};