#include <iostream>
using namespace std;

int main()
{
    // Declaring a string object
    // string str;
    // cout << "Enter a string: ";
    // getline(cin, str);

    // cout << "You entered: " << str << endl;

    string s;
    string s2;
    bool x{};
    cout << "Enter a string" << endl;
    while (cin >> s2)
    {

        s += s2 + " ";
    }
    cout << s << endl;

    return 0;
}