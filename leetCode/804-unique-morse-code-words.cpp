#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string morseMap[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string, int> morseCodes;
        int count = 0;
        for (auto word : words)
        {
            string mc = "";
            for (char letter : word)
            {
                mc += morseMap[letter - 'a'];
            }
            if (morseCodes[mc] == 0)
            {
                morseCodes[mc]++;
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution foo;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    auto ans = foo.uniqueMorseRepresentations(words);
    cout << "Result is " << ans << endl;
    return 0;
}