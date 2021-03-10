// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;

/* Function to swap values at two pointers */
void swap1(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char *str, int l, int r)
{

    if (l == r)
        cout << str << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap1((str + l), (str + i));
            permute(str, l + 1, r);
            swap1((str + l), (str + i)); //backtrack
        }
    }
}

void swap2(string &str, int from, int to)
{
    char temp = str[from];
    str[from] = str[to];
    str[to] = temp;
}

void permute2(string &str, int s, int e)
{
    if (s == e)
    {
        cout << str << endl;
        return;
    }

    for (int i = s; i <= e; i++)
    {
        swap2(str, s, i);
        permute2(str, s + 1, e);
        swap2(str, s, i); // backtracking to restore the string to it's initial value
    }
}

// we can also use the in-build swap function
void permute3(string &str, int s, int e)
{
    if (s == e)
    {
        cout << str << endl;
        return;
    }

    for (int i = s; i <= e; i++)
    {
        swap(str[s], str[i]);
        permute2(str, s + 1, e);
        swap(str[s], str[i]); // backtracking to restore the string to it's initial value
    }
}

/* Driver program to test above functions */
int main()
{
    // char str[] = "ABC";
    // int n = strlen(str);
    // permute(str, 0, n - 1);
    string str = "ABCD";

    permute2(str, 0, str.length() - 1);
    // cout << str << endl;

    return 0;
}
