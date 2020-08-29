        //Id and Ship

        #include <bits/stdc++.h>
        #define REP(i, a, n) for (i = a; i < n; i++)
        //#define rep(i, n) REP(i, 0, n)

        using namespace std;

        void printShip(char id)
        {
            switch (id)
            {
            case 'B':
            case 'b':
                cout << "BattleShip" << endl;
                break;
            case 'C':
            case 'c':
                cout << "Cruiser" << endl;
                break;
            case 'D':
            case 'd':
                cout << "Destroyer" << endl;
                break;
            case 'F':
            case 'f':
                cout << "Frigate" << endl;
                break;
            default:
                return;
            }
        }

        int main(int argc, char const *argv[])
        {
            int t = 0;
            cin >> t;
            while (t--)
            {
                char c;
                cin >> c;
                printShip(c);
            }
            return 0;
        }