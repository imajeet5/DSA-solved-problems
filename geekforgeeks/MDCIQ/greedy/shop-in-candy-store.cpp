// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        // if there is only single candy then max and min is same for buy that candy

        sort(candies, candies + N);
        vector<int> costs(2, 0);
        int minCost = 0;
        int maxCost = 0;
        int startIndex = 0;
        int endIndex = N - 1;
        int shouldBreak = false;
        // for min
        while (true)
        {
            // select on candy from start
            int fc = candies[startIndex];
            minCost += fc;
            if (startIndex == endIndex)
            {
                shouldBreak = true;
                break;
            }

            for (int i = 0; i < K; i++)
            {
                endIndex--;
                // while moving backward if we have reached at the staring index then break
                if (startIndex == endIndex)
                {
                    shouldBreak = true;
                    break;
                }
            }
            if (shouldBreak)
                break;
            startIndex++;
        }
        costs[0] = minCost;

        startIndex = 0;
        endIndex = N - 1;
        shouldBreak = false;
        while (true)
        {
            int lc = candies[endIndex];
            maxCost += lc;
            if (startIndex == endIndex)
            {
                shouldBreak = true;
                break;
            }
            for (int i = 0; i < K; i++)
            {
                startIndex++;
                if (startIndex == endIndex)
                {
                    shouldBreak = true;
                    break;
                }
            }

            if (shouldBreak)
                break;
            endIndex--;
        }
        costs[1] = maxCost;
        return costs;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
} // } Driver Code Ends

/* 

1
4 2
3 2 1 4
 */