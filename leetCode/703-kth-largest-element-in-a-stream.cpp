#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int m_k;

    KthLargest(int k, vector<int> &nums)
    {
        m_k = k;
        for (int n : nums)
        {
            add(n);
        }
    }

    int add(int val)
    {
        // if priority queue size is less the k elements size then we will
        // add the elements to the priority elements
        if (pq.size() < m_k)
        {
            pq.push(val);
        }
        else
        {
            // only add element to the heap if the incoming element is greater then
            // lowest element of the priority queue
            if (val > pq.top())
            {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
