#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}