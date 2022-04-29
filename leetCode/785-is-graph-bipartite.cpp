#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // total vertex
        int n = graph.size();
        // we will take a myset array, which is default to -1, means no values is added
        // 0 -> means values in first set and 2 -> value in second set
        vector<int> myset(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            // if the element is not visited
            if (myset[i] == -1)
            {
                // push the first element of the new graph into the queue
                q.push(i);
                // put the element initially in set 1
                myset[i] = 1;

                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for (auto child : graph[curr])
                    {
                        // if it has not been assigned any set
                        if (myset[child] == -1)
                        {
                            // we will assign it to the opposite set to the current element set
                            myset[child] = !myset[curr];
                            // also we will push it to the queue
                            q.push(child);
                        }
                        else if (myset[child] == myset[curr])
                        {
                            // if it is already in the set then if it is in the same set as it parent, then graph
                            // cannot be bipartide
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}