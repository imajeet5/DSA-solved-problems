// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
    void doFloodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int startingColor) {
        // Algo: 1. We have to use recursion
        int last_row_index = image.size() - 1; // index of last row
        int last_col_index = image[0].size() - 1; // index of last column
        // dont do anything if index is out of range
        if (sr > last_row_index || sc > last_col_index || sr < 0 || sc < 0) {
            return;
        }
        // don't do anything is color is diffent from starting color
        // or the image already have the new color
        if (image[sr][sc] != startingColor || image[sr][sc] == newColor) {
            return;
        }
        
        // replace color with starting color
        image[sr][sc] = newColor;

        // go top, bottom, left and right
        doFloodFill(image, sr + 1, sc, newColor, startingColor);
        doFloodFill(image, sr - 1, sc, newColor, startingColor);
        doFloodFill(image, sr, sc + 1, newColor, startingColor);
        doFloodFill(image, sr, sc - 1, newColor, startingColor);

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startingColor = image[sr][sc];
        doFloodFill(image, sr, sc, newColor, startingColor);
        return image;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends

/* 
1
3
3
1 1 1 1 1 0 1 0 1
1 1 
2
 */

/* 
1
2
3
0 0 0 0 1 1
1 1 
1
 */