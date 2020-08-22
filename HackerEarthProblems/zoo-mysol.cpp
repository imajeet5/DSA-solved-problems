#include <iostream>
#include <string>

using namespace std;

void validZoo(string *str)
{
    int x = 0;
    int y = 0;
    for (auto s : *str)
    {
        if (s == 'z')
        {
            x++;
        }
        if (s == 'o')
        {
            y++;
        }
    }
    if ((2 * x == y))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main(int argc, char const *argv[])
{
    string x{};
    cin >> x;
    validZoo(&x);

    return 0;
}