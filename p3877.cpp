#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> team(N,0);
    int maxpassenger=0;
    int sumpassenger=0;
    for (int i=0;i< N;i++)
    {
        cin >> team[N];
        sumpassenger+=team[N];
        maxpassenger=max(maxpassenger,team[N]);
    }


    int cnt = 1;
    long long sum = 0;
    for (int mid=maxpassenger;mid<=sumpassenger;mid++)
    {
        for (int i = 0; i < N; i++)
        {
            if (sum + team[i] <= mid)
            {
                sum +=team[i];
            }
            else
            {
                cnt++;
                sum = team[i];
            }
            if (cnt>M)
            {

            }
        }
    }


}
