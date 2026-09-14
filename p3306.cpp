#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int areaRequirement, budget, n;
    cin >> areaRequirement >> budget >> n;

    vector<int> dp(budget + 1, 0);

    // 读取每个接入点并做 0/1 背包
    for (int i=1;i<=n;i++) {
        int courage,cost;
        cin>> courage>>cost;
        for(int j=budget ;j>=cost;j--)
        {
            dp[j]=max(dp[j-cost]+courage,dp[j]);
        }
    }

    // 查找最小预算
    for (int k=0;k<=budget ;k++) {
        if( dp[k]>=areaRequirement ){
        cout<<k<<" "<<dp[k]<<endl;
        return 0;
    }
    }

    // 如果没找到
    cout<<"0"<<" 0"<<endl;

    return 0;
}