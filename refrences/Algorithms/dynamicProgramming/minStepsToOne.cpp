#include <bits/stdc++.h>

using namespace std;

long int counter = 0;

// priority_queue<int, vector<int>, greater<int>> path;
// vector<int> path2;

int minStepsToOne(int num)
{
    counter++;
    if (num == 1 || num == 0)
    {
        return 0;
    }
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;

    x = minStepsToOne(num - 1);
    if (num % 2 == 0)
    {
        y = minStepsToOne(num / 2);
    }
    if (num % 3 == 0)
    {
        z = minStepsToOne(num / 3);
    }

    return min(x, min(y, z)) + 1;
}

int minStepsToOne2(int num, int *arr)
{

    if (num == 1 || num == 0)
    {
        return 0;
    }
    if (arr[num] != -1)
    {
        return arr[num];
    }
    counter++;

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;

    x = minStepsToOne2(num - 1, arr);

    if (num % 2 == 0)
    {
        y = minStepsToOne2(num / 2, arr);
    }
    if (num % 3 == 0)
    {
        z = minStepsToOne2(num / 3, arr);
    }

    int steps = min(x, min(y, z)) + 1;
    arr[num] = steps;

    return steps;
}
int minStepsToOne3(int n)
{

    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 0;

    // dp[i] = min steps needed to move from i to 1
    for (int i = 2; i <= n; i++)
    {
        int x, y, z;
        y = z = INT_MAX;
        x = dp[i - 1];
        if (i % 2 == 0)
            y = dp[i / 2];
        if (i % 3 == 0)
            z = dp[i / 3];
        dp[i] = min(x, min(y, z)) + 1;
    }

    int steps = dp[n];

    delete[] dp;

    return steps;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a integer " << endl;
    cin >> n;
    int arr[n + 1];
    for (size_t i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    cout << "Minimum Steps to one (using iterative dp): " << minStepsToOne3(n) << endl;

    cout << "Minimum Steps to one (using Recursion Memoization): " << minStepsToOne2(n, arr) << endl;

    cout << "Minimum Steps to one (using Recursion Brute): " << minStepsToOne(n) << endl;

    // while (!path.empty())
    // {
    //     cout << path.top() << " ";
    //     path.pop();
    // }
    // for (size_t i = 0; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    cout << endl;

    return 0;
}

/*

int minStepsToOne2(int num, int *arr)
{
    counter++;
    if (num == 1 || num == 0)
    {
        return 0;
    }
    if (arr[num] != -1)
    {
        return arr[num];
    }

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;

    x = minStepsToOne2(num - 1, arr);
    // storing minStepsToOne for number num -1;
    arr[num - 1] = x;
    if (num % 2 == 0)
    {
        y = minStepsToOne2(num / 2, arr);
        // storing minStepsToOne for number num / 2;
        arr[num / 2] = y;
    }
    if (num % 3 == 0)
    {
        z = minStepsToOne2(num / 3, arr);
        // storing minStepsToOne for number num / 3;
        arr[num / 3] = y;
    }

    return min(x, min(y, z)) + 1;
}


*/