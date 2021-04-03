#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int> m1, pair<int, int> m2)
{
    // we have to sort in the ascending order
    if (m1.second < m2.second)
        return true;
    else if (m1.second > m2.second)
        return false;
    return false;
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}