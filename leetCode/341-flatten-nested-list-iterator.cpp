#include <bits/stdc++.h>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
private:
    stack<NestedInteger> s;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        for (int i = n - 1; i > 0; i--)
        {
            s.push(nestedList[i]);
        }
    }

    int next()
    {
        // this next function will only be called after the hasNext function,
        // so we can be sure the top element of the stack must be an int value as hasNext has already been executed
        int result = s.top().getInteger();
        s.pop();
        return result;
    }

    bool hasNext()
    {
        // we will run this loop until we don't find an integer value
        while (!s.empty())
        {
            auto curr = s.top();
            if (curr.isInteger())
            {
                return true;
            }
            // remove the current element from the stack, as it is a list and we are going to put the
            // element inside the list in the stack
            s.pop();

            auto list = curr.getList();
            // push all the
            for (int i = list.size() - 1; i > 0; i--)
            {
                s.push(list[i]);
            }
            // now after push the element of nested list we will again check if the while loop if we have found the int value
        }
        // if stack becomes empty and we didn't find any integer value we will return false
        return false;
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