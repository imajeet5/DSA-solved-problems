#include <bits/stdc++.h>

using namespace std;






int main(int argc, char const *argv[])
{
    int *arr = new int[10];
    int a[10];
    int *p;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    p = a+2;
    
    // arr[1] = 10;
    
    cout << (a+1) << "||"<< p << "||" << (a+3) << endl;
    
    return 0;
}