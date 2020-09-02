#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

void duplicateZerosNoTemp(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] == 0)
        {
            arr.insert(arr.begin() + i, 0);
            arr.pop_back();
            i++;
        }
    }
    // int remove = temp.size() - arr.size();
    // for (int j = 0; j < remove; j++)
    // {
    //     temp.pop_back();
    // }

    // arr = temp;

    // for (auto i = temp.begin(); i != temp.end(); i++)
    // {
    //     if (*i == 0)
    //     {
    //         arr.insert(i, 0);
    //     }
    // }
}

void duplicateZerosTemp(vector<int> &arr)
{
    vector<int> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        if (arr[i] == 0)
        {
            temp.push_back(0);
        }
    }
    int remove = temp.size() - arr.size();
    for (int j = 0; j < remove; j++)
    {
        temp.pop_back();
    }

    arr = temp;

    for (auto i = temp.begin(); i != temp.end(); i++)
    {
        if (*i == 0)
        {
            arr.insert(i, 0);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 0, 2, 3, 0, 4, 5, 0};

    duplicateZerosTemp(nums);
    printVec(nums);
    return 0;
}