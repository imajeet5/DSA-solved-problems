// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Box
{

public:
    int height, width, length;

    Box(int height, int side1, int side2)
    {
        this->height = height;
        if (side1 >= side2)
        {
            this->length = side1;
            this->width = side2;
        }
        else
        {
            this->length = side2;
            this->width = side1;
        }
    }
};

bool comparator(Box box1, Box box2)
{
    // we have to sort in the descending order of the areas
    int area1 = box1.length * box1.width;
    int area2 = box2.length * box2.width;

    if (area2 >= area2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Solution
{
public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/

    vector<Box> createAllBoxes(int height[], int width[], int length[], int n)
    {
        vector<Box> allBoxes(n * 3);
        for (int i = 0; i < n; i++)
        {
            allBoxes.push_back(Box(height[i], length[i], width[i]));
            allBoxes.push_back(Box(length[i], height[i], width[i]));
            allBoxes.push_back(Box(width[i], length[i], height[i]));
        }

        return allBoxes;
    }

    int maxHeight(int height[], int width[], int length[], int n)
    {
        //Your code here
        vector<Box> allBoxes = createAllBoxes(height, width, length, n);
        int totalBoxes = allBoxes.size();

        sort(allBoxes.begin(), allBoxes.end(), comparator);

        // now apply longest increaseing subsequence kind of algorithm
        // dp represent the max height as
        int dp[totalBoxes] = {};
        int results[totalBoxes] = {};
        // assign default values to each
        for (int i = 0; i < totalBoxes; i++)
        {
            dp[i] = allBoxes[i].height;
            results[i] = i;
        }

        int maxVal = 0;

        for (int i = 1; i < totalBoxes; i++)
        { // for each i we will start from zero when and check
            //1. if dimesion of the ith box is less then the jth box as jth box is at the bottom
            //2. if max height at j + the current heigh of the ith element is greater then the current max height
            // of the element then replace
            for (int j = 0; j < i; j++)
            {
                if (allBoxes[i].length < allBoxes[j].length && allBoxes[i].width < allBoxes[j].width)
                {
                    if (dp[j] + allBoxes[i].height > dp[i])
                    {
                        dp[i] = dp[j] + allBoxes[i].height;
                        results[i] = j;
                    }
                }
            }

            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int A[105], B[105], C[105];
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            A[i] = a;
            B[i] = b;
            C[i] = c;
        }
        Solution ob;
        cout << ob.maxHeight(A, B, C, n) << endl;
    }

} // } Driver Code Ends