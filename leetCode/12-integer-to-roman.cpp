#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        // we will create map for every digit from 1 to 9
        // for thousand palace
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};