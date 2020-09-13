/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int tests;
    scanf("%d", &tests);
    char input[10000];
    for (int k = 0; k < tests; k++)
    {
        scanf("%s", input);

        for (int i = 0; i < strlen(input); i += 2)
        {
            printf("%c", input[i]);
        }
        printf(" ");
        for (int i = 1; i < strlen(input); i += 2)
        {
            printf("%c", input[i]);
        }
        printf("\n");
    }
    return 0;
}

*/

/*

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void takeInput(vector<string> *vec, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        string s;
        getline(cin >> ws, s);
        vec->push_back(s);
    }
}

void print(string *str)
{

    string evenS, oddS;
    for (int i{0}; i < str->length(); i++)
    {
        if (i % 2 == 0) // even
        {
            evenS += str->at(i);
        }
        else
        {
            oddS += str->at(i);
        }
    }
    cout << evenS << "  " << oddS << endl;
}

int main()
{
  
    int lines;
    vector<string> strings;
    cin >> lines;
    takeInput(&strings, lines);
    for (auto v : strings)
        print(&v);

    return 0;
}

*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(string *);

void takeInputAndPrint(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        string s;
        getline(cin >> ws, s);
        print(&s);
        
    }
}

void print(string *str)
{

    string evenS, oddS;
    for (int i{0}; i < str->length(); i++)
    {
        if (i % 2 == 0) // even
        {
            evenS += str->at(i);
        }
        else
        {
            oddS += str->at(i);
        }
    }
    cout << evenS << "  " << oddS << endl;
}

int main()
{
  
    int lines;  
    cin >> lines;
    takeInputAndPrint(lines);
    return 0;
}

