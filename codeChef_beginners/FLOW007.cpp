// Reverse the Number

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string num;
        getline(cin >> ws, num);
        reverse(num.begin(), num.end());
        cout << stoi(num) << endl;
    }
    return 0;
}
//using int
int main2() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n,d,r=0;
	    cin>>n;
	    while(n)
	    {
	       d=n%10;
	       r=r*10+d;
	       n=n/10;
	        
	    }
	    cout<<r<<endl;
	}
	return 0;
}