//Packaging Cupcakes

#include <bits/stdc++.h>

using namespace std;

int getRemainingCakes(int cakes)
{
    if (cakes % 2 == 0)
    {
        return (cakes / 2) + 1;
    }
    else
    {
        return (cakes + 1) / 2;
    }
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int cakes;
        cin >> cakes;
        cout << getRemainingCakes(cakes) << endl;
    }
    return 0;
}