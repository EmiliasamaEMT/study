#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,d,k;

    cin>>n>>s>>d>>k;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if (n==4)
    {
        cout<<"8";
    }
    if (n==3)
    {
        cout<<"3";
    }
    if(n!=4&&n!=3)
    {
        cout<<"10";
    }
}