#include <iostream>
#include <vector>

using namespace std;

int getBinary(int n)
{
    vector<int> binary_vec;
    while (n != 0)
    {

        binary_vec.push_back(n % 2);
        n /= 2;
    }
    int counter = 0;
    int consequtiveOnes = 0;
    for (auto i = binary_vec.rbegin(); i != binary_vec.rend(); i++)
    {
        if (*i == 0)
        {
            counter = 0;
        }
        else
        {
            counter++;
            if (counter >= consequtiveOnes)
            {
                consequtiveOnes = counter;
            }
        }
    }
    return consequtiveOnes;
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << getBinary(x) << endl;
    return 0;
}