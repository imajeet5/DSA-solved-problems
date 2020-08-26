//Ciel and Receipt
#include <bits/stdc++.h>

using namespace std;

int items = 0;

int getMenuItems(int p, const vector<int> prices)
{
    if (p == 1)
    {
        items++;
        return items;
    }
    int immediateLast = 0;
    for (auto price : prices)
    {
        if (price <= p)
        {
            immediateLast = price;
        }
    }
    if (immediateLast == p)
    {
        items++;
        return items;
    }
    if (p > immediateLast)
    {
        items++;
        return getMenuItems(p - immediateLast, prices);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> prices(12);
    prices.at(0) = 1;
    for (int i = 1; i <= 11; i++)
    {
        prices.at(i) = prices.at(i - 1) * 2;
    }

    int n = 0;
    cin >> n;
    while (n--)
    {
        int p;
        cin >> p;
        items = 0;
        cout << getMenuItems(p, prices) << endl;
    }
    return 0;
}