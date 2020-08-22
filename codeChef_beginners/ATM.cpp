#include <iostream>
#include <iomanip>

using namespace std;

float withdraw(int w, float amt)
{
    if (w + 0.5 > amt)
    {
        return amt;
    }
    if (w % 5 != 0)
    {
        return amt;
    }
    return amt - w - 0.50;
}

int main(int argc, char const *argv[])
{
    int w_amt{0};
    float t_amt{0};

    cin >> w_amt >> t_amt;    

    cout << setprecision(2) << fixed << withdraw(w_amt, t_amt) << endl;

    return 0;
}