#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

string vectorTostring(vector<int> &vec)
{
    std::ostringstream vts;
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int>(vts, ""));
    string res = vts.str();
    res.insert(2, ":");
    return res;
}

string largestTimeFromDigits(vector<int> &A)
{
    int n = A.size();
    string empty = "";

    vector<int> largestTime;
    sort(A.begin(), A.end());
    // sort the array and if first digit is greater then or equal to 3 them return empty
    if (A[0] >= 3)
    {

        return empty;
    };
    if (A[0] == 2 && A[1] >= 4)
    {
        return empty;
    };
    if ((A[0] == 0 || A[0] == 1) && A[1] == 2 && A[2] >= 6)
    {
        largestTime.push_back(A[0]);
        A.erase(A.begin());
        auto max = max_element(A.begin(), A.end());
        largestTime.push_back(*max);
        A.erase(max);

        if (A[1] < 6)
        {
            largestTime.push_back(A[1]);

            largestTime.push_back(A[0]);
            return vectorTostring(largestTime);
        }
        else
        {
            largestTime.push_back(A[0]);

            largestTime.push_back(A[1]);
            return vectorTostring(largestTime);
        }
    };
    // index of first digit, initially set to last index
    int f = 3;
    for (int i = 1; i < n; i++)
    {
        // find first element greater than 2 and take element before it.
        // as the array is sorted it must be 0 or 1
        if (A[i] > 2)
        {
            f = i - 1;
            break;
        }
    }

    largestTime.push_back(A[f]);
    auto b = A.begin();
    // erase the found index as it has been used
    A.erase(b + f);
    // now if the first element of the sorted array is greater then 3 then it is not valid and largestTime has 2 as first
    if (largestTime[0] == 2 && A[0] > 3)
    {
        return empty;
    }
    // if first digit is 0 or 1, next digit can be from 0 to 9
    if (largestTime[0] < 2)
    {
        f = 0;
        int max = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] > max)
            {
                f = i;
                max = A[i];
            }
        }
        // get the max of remaining digits and push it into array
        largestTime.push_back(max);
        // erase that maximum digit
        A.erase(b + f);
    }

    else
    {
        // if first digit is 2 then next digit can be from 0 to 3
        // from the remaining digit find the index of digit just before the digit greater than 3, that can be 3 or less then 3
        f = 2;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] > 3)
            {
                f = i - 1;
                break;
            }
        }
        largestTime.push_back(A[f]);
        A.erase(b + f);
    }

    // one of the number has to be less then 5 to make 59
    if (A[0] > 5)
    {
        return empty;
    }

    // now only two digits are remaining
    

    if (A[1] < 6)
    {
        largestTime.push_back(A[1]);
        largestTime.push_back(A[0]);
        return vectorTostring(largestTime);
    }
    else
    {
        largestTime.push_back(A[0]);
        largestTime.push_back(A[1]);
        return vectorTostring(largestTime);
    }
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        vector<int> A(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> A.at(i);
        }
        string result = largestTimeFromDigits(A);
        cout << result << endl;
    }
    return 0;
}