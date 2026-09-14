#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        int hp=m;
        vector<int> a(n),b(n);
        vector<bool> c(n);
        for (int j=0;j<n;j++)
        {
            cin>>a[j]>>b[j];
            if (a[j]<b[j])
                c[j]=true;
            else
                c[j]=false;
        }


    }
}
