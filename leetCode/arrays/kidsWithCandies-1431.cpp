// candies
// extra candies
// candie[i] number of candies ith kid has.

#include <bits/stdc++.h>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<bool> result(candies.size(), false);
    // int maxIndex = 0;
    // for (size_t i = 1; i < candies.size(); i++)
    // {
    //     if (candies.at(i) > candies.at(maxIndex))
    //         maxIndex = i;
    // }

    // int maxValue = candies[maxIndex];
    int maxValue = *max_element(candies.begin(), candies.end());

    for (size_t i = 0; i < candies.size(); i++)
    {
        if ((maxValue - candies.at(i)) <= extraCandies)
        {
            result.at(i) = true;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> candies{2, 3, 5, 1, 3};
    int ec = 3;
    vector<bool> result = kidsWithCandies(candies, ec);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result.at(i) << " ";
    }

    return 0;
}
