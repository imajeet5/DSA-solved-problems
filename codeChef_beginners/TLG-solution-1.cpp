#include <iostream>
using namespace std;
int k;
int modulus1(int a)
{
    if (a > 0)
        k = a;
    else
        k = -a;
    return k;
}

int main()
{
    int i, rounds, j, q, l, s;
    cin >> rounds;
    int playerone[rounds];   //stores scores of player one in each round
    int playertwo[rounds];   //stores scores of player two in each round
    int lead[rounds];        //stores lead of player one over player 2
    int moduluslead[rounds]; //stores modulus of lead
    s = 0;
    for (i = 0; i < rounds; i++)
    {
        cin >> playerone[i];
        cin >> playertwo[i];
        s = s + playerone[i] - playertwo[i];
        lead[i] = s;
        moduluslead[i] = modulus1(lead[i]);
    }
    j = moduluslead[0];
    q = 0;
    for (i = 1; i < rounds; i++) //loop to find modulus of maximum lead
    {
        if (moduluslead[i] > j)
        {
            j = moduluslead[i];
            q = i;
        }
    }
    l = 2;
    if (lead[q] > 0)
        l = 1;
    cout << l << " " << moduluslead[q];
}