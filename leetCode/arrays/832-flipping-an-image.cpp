#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        vector<vector<int>> ans(image.size(), vector<int>(image[0].size(), 0));

        // first loop for the row
        for (int i = 0; i < image.size(); i++)
        {
            // second loop for the cols
            int k = 0;
            for (int j = image[i].size() - 1; j >= 0; j--)
            {

                // we will use this loop in reverse order to flip the image horizontally
                int curr = !image[i][j];
                ans[i][k] = curr;
                k++;
            }
        }

        return ans;
    }
};