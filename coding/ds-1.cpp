#include <bits/stdc++.h>

using namespace std;

class my_pair
{
    int z = 3;

public:
    int x = 0;
    int y = 0;

    int getSum()
    {
        return this->x + this->y + this->z;
    }
};

int main(int argc, char const *argv[])
{
    // int arr[6] = {10, 20, 30, 40};

    // char c[] = 'abcd';

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(12);

    // my_pair mp;
    // mp.x = 10;
    // mp.y = 20;

    // my_pair mp2;
    // mp2.x = 1;
    // mp2.y = 2;

    // cout << mp2.x << endl;
    // cout << mp2.y << endl;
    // cout << mp2.getSum() << endl;

    // cout << v.size() << endl;
    int x = 10;
    int y = 20;
    string *sp = new string;
    *sp = "abc";
    string *sp2 = new string;
    *sp2 = "def";
    
    &x = &y;

    
    
    
    


    // cout << sp << endl;
    // cout << *sp << endl;

    cout << sp << endl;
    cout << sp2 << endl;

    return 0;
}