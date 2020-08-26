// The Lead Game

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;

    cin >> n;
    vector<int> playerOneScores(n), playerTwoScores(n);
    int leader = 1;
    int lead = 0;

    for (int i = 0; i < n; i++)
    {
        int s1 = 0, s2 = 0;
        cin >> s1 >> s2;
        if (i == 0)
        {
            playerOneScores.at(i) = s1;
            playerTwoScores.at(i) = s2;
        }
        else
        {
            playerOneScores.at(i) = s1 + playerOneScores.at(i - 1);
            playerTwoScores.at(i) = s2 + playerTwoScores.at(i - 1);
        }
        int currentLead = playerOneScores.at(i) - playerTwoScores.at(i);
        if (abs(currentLead) >= lead)
        {
            lead = abs(currentLead);
            leader = currentLead > 0 ? 1 : 2;
        }
    }
    cout << leader << " " << lead << endl;

    return 0;
}