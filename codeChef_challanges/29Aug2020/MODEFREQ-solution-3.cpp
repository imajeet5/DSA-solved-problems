#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[11] = {0};

        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);

            arr[num]++;
        }
        int largeMod = 0;
        int arr1[n + 1] = {0};
        int large = 0;

        for (int i = 0; i < 11; i++)
        {
            if (arr[i] != 0)
            {

                arr1[arr[i]]++;
            }
        }

        int freq = 0;
        for (int i = 0; i < n + 1; i++)
        {

            if (arr1[i] != 0)
            {
                if (arr1[i] > largeMod)
                {
                    largeMod = arr1[i];
                    freq = i;
                }
                else if (arr1[i] == largeMod)
                {

                    if (i < freq)
                        freq = i;
                }
            }
        }

        printf("%d\n", freq);
    }
    return 0;
}
