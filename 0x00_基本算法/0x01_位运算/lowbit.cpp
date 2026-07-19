#include<bits/stdc++.h>
using namespace std;

int lowbit(int n)
{
    return n&(-n);
}

int main()
{


 int n;
 cin>>n;

 cout << "lowbit of " << n << " is: " << lowbit(n) << endl;


    return 0;
}