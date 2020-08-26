#include <iostream>
#include <cmath>
using namespace std;
int main()
{

    int t;
    cin >> t;
    int arr[13] = {0};
    for (int i = 1; i <= 12; i++)
        arr[i] = pow(2, i - 1);
    while (t--)
    {
        int p;
        int count = 0;
        cin >> p;
        for (int i = 12; i > 0;)
        {
            if (arr[i] <= p)
            {
                p = p - arr[i];
                count++;
            }
            if (arr[i] > p)
            {
                i--;
            }
            if (p == 0)
                break;
        }
        cout << count << endl;
    }
    return 0;
}