#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n,K;
    cin>>n>>K;
    vector<vector<int>> fes(n,vector<int>(2,0));
    for (int i = 0; i < n; i++)
    {

        cin>>fes[i][0]>>fes[i][1];

    }



    int left = 0;
    int sumM = 0;
    int sumJ = 0;
    int ans = 0;

    for (int right = 0; right < n; right++)
    {
        // 把right加入窗口
        sumM += fes[right][1];
        sumJ += fes[right][0];

        // 如果人力超限，缩小左边
        while (sumM > K)
        {
            sumM -= fes[left][1];
            sumJ -= fes[left][0];
            left++;
        }

        ans = max(ans, sumJ);
    }
    cout<<ans;
}
