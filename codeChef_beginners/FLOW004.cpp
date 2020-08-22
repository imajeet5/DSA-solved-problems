//First and Last Digit

#include <bits/stdc++.h>

using namespace std;

// my sol using string
int main2(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string num;
        getline(cin >> ws, num);
        int last = num.at(num.size() - 1) - '0';
        int first = num.at(0) - '0';
        cout << first + last << endl;
    }
    return 0;
}

int get_first_digit(int num)
{
    int num_digits = 0;
    int temp = num;
    while (temp)
    {
        temp = temp / 10;
        num_digits++;
    }
    
    return num / pow(10, num_digits - 1);
}


// using int
int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        int last_digit = num % 10;
        int first_digit = get_first_digit(num);
        cout << first_digit + last_digit << endl;
    }
    return 0;
}