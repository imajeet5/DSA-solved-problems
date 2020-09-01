#include <iostream>

using namespace std;

int fun(int n){
    if(n == 0){
        return 0;
    }
    return n + fun(n - 1);
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << fun(x) << endl;
    return 0;
}
