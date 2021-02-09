// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k);

int main()
{

    int n, k;
    cin >> n >> k; //taking input n and k

    //calling josephus() function
    cout << josephus(n, k) << endl;

    return 0;
} // } Driver Code Ends

/*You are required to complete this method */

int solve(vector<int> persons, int k, int ci)
{
    if (persons.size() == 1)
    {
        return persons[0];
    }
    ci = (ci + k) % (persons.size() - 1);
    vector<int> remaining_persons;
    for (int i = 0; i < persons.size(); i++)
    {
        if (i != ci)
            remaining_persons.push_back(persons[i]);
    }

    return solve(remaining_persons, k, ci);
}
// Didn't worked
int josephus2(int n, int k)
{
    vector<int> persons;
    for (int i = 0; i < n; i++)
        persons.push_back(i);
    k--;        // increment
    int ci = 0; // current index

    solve(persons, k, ci);
}

int josephus(int n, int k)
{
    //Your code here

    int i = 0;
    while (n > pow(k, i))
    {
        i++;
    }
    int remaining = n - pow(k, i - 1);

    return 2 * remaining + 1;
}
