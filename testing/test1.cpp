#include <bits/stdc++.h>

using namespace std;



void function(int a[][3]){
    ++a;
    a[1][1];
}


int main(int argc, char const *argv[])
{
int a[3][3] = {1,2,3,4,5,6,7,8,9};
cout << a[2][1] - a[1][2];
return 0;
}