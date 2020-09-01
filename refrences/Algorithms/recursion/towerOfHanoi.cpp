#include <iostream>

using namespace std;


int steps = 0;

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);    
        printf("(%d , %d)\n", A, C);
        steps++;
        TOH(n - 1, B, A, C);
    }
}

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter disks" << endl;
    cin >> x;
    TOH(x, 1, 2, 3);
    cout << "Total Steps: " << steps << endl;
    return 0;
}