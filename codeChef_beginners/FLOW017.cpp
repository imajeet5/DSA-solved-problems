//Second Largest
#include <bits/stdc++.h>

using namespace std;

int getLargest(vector<int> numbers)
{
    int largestIndex = 0;
    int largest = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers.at(i) > largest)
        {
            largest = numbers.at(i);
            largestIndex = i;
        }
    }

    return largestIndex;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    while (n--)
    {
        vector<int> nums(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> nums.at(i);
        }
        nums.erase(nums.begin() + getLargest(nums));
        cout << nums.at(getLargest(nums)) << endl;
    }
    return 0;
}