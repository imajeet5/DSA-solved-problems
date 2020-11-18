// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump[], int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n) << endl;
    }
}
// } Driver Code Ends

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[], int n)
{
    //Your code here
    int sum = 0, start = 0, diff = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (p[i].petrol - p[i].distance);
        if (sum < 0)
        {
            start = i + 1;
            diff += sum;
            sum = 0;
        }
    }
    return sum + diff > 0 ? start : -1;
}
