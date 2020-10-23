#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void findPlatform1(int arr[], int dep[], int n)
{
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process
    // all events in sorted order
    while (i < n && j < n)
    {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] <= dep[j])
        {
            plat_needed++;
            i++;

            // Update result if needed
            if (plat_needed > result)
                result = plat_needed;
        }

        // Else decrement count of platforms needed
        else
        {
            plat_needed--;
            j++;
        }
    }

    cout << result << endl;
}

int findPlatform2(int arr[], int dep[], int n)
{
    // Insert all the times (arr. and dep.)
    // in the multimap.
    multimap<int, char> order;
    for (int i = 0; i < n; i++)
    {

        // If its arrival then second value
        // of pair is 'a' else 'd'
        
        order.insert(make_pair(arr[i], 'a'));
        order.insert(make_pair(dep[i], 'd'));
    }

    int result = 0;
    int plat_needed = 0;

    multimap<int, char>::iterator it = order.begin();

    // Start iterating the multimap.
    for (; it != order.end(); it++)
    {

        // If its 'a' then add 1 to plat_needed
        // else minus 1 from plat_needed.
        if ((*it).second == 'a')
            plat_needed++;
        else
            plat_needed--;

        if (plat_needed > result)
            result = plat_needed;
    }
    cout << result << endl;
    return result;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    findPlatform2(arr, dep, n);

    return 0;
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> dep[i];
        }
        findPlatform2(arr, dep, n);
    }
    return 0;
}