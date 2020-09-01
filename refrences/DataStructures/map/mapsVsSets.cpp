#include <bits/stdc++.h>

using namespace std;

/*
map<key_class,value_class> will sort on key_class and allow no duplicates of key_class.
set<pair<key_class,value_class> > will sort on key_class and then value_class if the key_class instances are equal, and will allow multiple values for key_class
*/

int main(int argc, char const *argv[])
{
    set<pair<char, int>> s1;
    s1.insert({'a', 10});
    s1.insert({'a', 11});
    s1.insert({'b', 10});
    map<char, int> m1;
    m1.insert({'a', 10});
    m1.insert({'c', 11});
    m1.insert({'b', 10});

   

    return 0;
}