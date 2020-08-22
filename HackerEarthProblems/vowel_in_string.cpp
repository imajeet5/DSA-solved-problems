#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // Declare variables to store count of vowels
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    string s;
    // Read given string from STDIN
    cin >> s;

    int s_len = s.length();
    // Iterate over each character in the string
    for (int j = 0; j < s_len; j++)
    {

        // This can be done in a better way using hashing, which simplifies the implementation,
        // however for the purpose of this article we'll restrict the implementation to naive way

        // Check for each character in if else
        if (s[j] == 'a')
        {
            a++;
        }
        else if (s[j] == 'e')
        {
            e++;
        }
        else if (s[j] == 'i')
        {
            i++;
        }
        else if (s[j] == 'o')
        {
            o++;
        }
        else if (s[j] == 'u')
        {
            u++;
        }
    }
    // Print out the result to STDOUT
    cout << "a " << a << endl;
    cout << "e " << e << endl;
    cout << "i " << i << endl;
    cout << "o " << o << endl;
    cout << "u " << u << endl;
    return 0;
}