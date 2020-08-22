#include <iostream>

#include <string.h>

using namespace std;

int main()
{

    int t;

    cin >> t;

    string s1, s2;

    int i;

    while (t--)
    {

        int count = 0;

        cin >> s1 >> s2;

        int fc[26] = {0}, fc2[26] = {0};

        for (i = (int)(s1.length()); i > 0; i--)
        {

            fc[(int)(s1[i - 1]) - 97]++;
        }

        for (i = (int)(s2.length()); i > 0; i--)
        {

            fc2[(int)(s2[i - 1]) - 97]++;
        }

        for (i = 0; i < 26; i++)
        {

            if (fc[i] > fc2[i])
            {
                count = count + (fc[i] - fc2[i]);
            }

            else if (fc2[i] > fc[i])
            {
                count = count + (fc2[i] - fc[i]);
            }
        }

        cout << count << endl;

        count = 0;
    }

    return 0;
}
