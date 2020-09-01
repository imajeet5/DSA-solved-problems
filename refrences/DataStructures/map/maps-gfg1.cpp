#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> map_int;
    map<string, int> map_string;
    map_int = {
        {3, 30},
        {2, 22},
        {1, 10}};
    map_string = {
        {"GfG", 3},
        {"To", 2},
        {"Welcome", 1}};

     
    for (auto m : map_string)
    {
        cout << m.first << " " << m.second << endl;
    }

    return 0;
}