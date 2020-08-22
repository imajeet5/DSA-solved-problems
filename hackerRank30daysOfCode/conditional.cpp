#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n % 2 == 1)
        cout << "Weird" << endl;
    else if (n >= 6 && n <= 20)
        cout << "Wierd" << endl;

    else
        cout << "Not Weird" << endl;

    return 0;
}
