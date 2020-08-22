#include <bits/stdc++.h>

using namespace std;

void max_hourglass(vector<vector<int>> arr)
{
    int max_sum = 0;
    for (int j = 0; j <= 3; j++)
    {
        for (int i = 0; i <= 3; i++)
        {
            int this_hourglass_sum = arr[j + 1][i + 1];
            int k = i;
            int l = k + 3;
            while (k < l)
            {
                this_hourglass_sum += arr[j][k];
                this_hourglass_sum += arr[j + 2][k];
                k++;
            }
            if (this_hourglass_sum > max_sum || i == 0 && j == 0)
                max_sum = this_hourglass_sum;
        }
    }
    cout << max_sum << endl;
};

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++)
    {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    max_hourglass(arr);

    return 0;
}
