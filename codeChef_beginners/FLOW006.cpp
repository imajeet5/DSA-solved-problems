// Sum of digits
#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a);

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << endl;
}

//Code Chef
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n = n / 10;
        }
        cout << sum << endl;
    }
    // your code goes here
    return 0;
}

// My sol
int main2(int argc, char const *argv[])
{
    int T = 0;
    cin >> T;
    vector<int> sums(T);
    for (int i = 0; i < T; i++)
    {
        string num;
        int tempSum = 0;

        getline(cin >> ws, num);
        for (auto n : num)
        {
            tempSum += n - '0';
        }
        sums.at(i) = tempSum;
    }
    printVec(sums);
    return 0;
}