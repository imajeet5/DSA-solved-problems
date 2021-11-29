#include <bits/stdc++.h>

using namespace std;

class StockSpanner
{
public:
    // price, span
    stack<pair<int, int>> s;

    StockSpanner()
    {
    }

    int next(int price)
    {

        int span = 1;
        // in the stack elenent will be store in the increasing order of their prices
        // with that price we will store the span
        // when an element that is greater then the elements of the stack, then we will pop the element of the stack
        // and get the corresponding span values and add it to current
        while (!s.empty() && s.top().first <= price)
        {
            // we will increase the current span count
            span += s.top().second;
            s.pop();
        }

        // now we will push the current price with it span into the stack
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */