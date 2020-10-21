#include <bits/stdc++.h>

// optimized solution of the problem is pending

using namespace std;

class Solution
{
public:
    long long countPairs(int X[], int Y[], int m, int n)
    {
        // code here
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pow(X[i], Y[j]) > pow(Y[j], X[i]))
                    ans++;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    freopen("_input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int X[m], Y[n];
        for (int i = 0; i < m; i++)
        {
            cin >> X[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> Y[i];
        }
        Solution ob;
        auto ans = ob.countPairs(X, Y, m, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends

/*
1
42 68
335 1 170 225 479 359 463 465 206 146 282 328 462 492 496 443 328 437 392 105 403 154 293 383 422 217 219 396 448 227 272 39 370 413 168 300 36 395 204 312 323 334
174 165 142 212 254 369 48 145 163 258 38 360 224 242 30 279 317 36 191 343 289 107 41 443 265 149 447 306 391 230 371 351 7 102 394 49 130 124 85 455 257 341 467 377 432 309 445 440 127 324 38 39 119 83 430 42 334 116 140 159 205 431 478 307 174 387 22 246

Its Correct output is:
928

And Your Code's output is:
179




*/