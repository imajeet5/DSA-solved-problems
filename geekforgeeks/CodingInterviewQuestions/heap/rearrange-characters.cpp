#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;



void getAnswer(string s) {
    int n = s.length();
    unordered_map<int, int>m;
    int mxFreq = 0;
    for (int i = 0; i < n; i++) {
        m[s[i]]++;
        if (m[s[i]] > mxFreq) {
            mxFreq = m[s[i]];
        }
    }
    // if the max frequency is less then the remaining character in the string then it can be rearranges
    // otherwise not
    if (mxFreq <= n - mxFreq + 1) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

}


int main(int argc, char const* argv[]) {

    int t = 0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        getAnswer(s);
    }
    return 0;
}