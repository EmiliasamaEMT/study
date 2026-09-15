#include <bits/stdc++.h>
using namespace std;
struct Query
{
    int start;  // 时间区间起点
    int id;     // 原来的输入位置
};

bool cmp(Query a, Query b)
{
    return a.start < b.start;
}
int main()
{
    //IN
    int N,X,K;
    cin>>N>>X>>K;

    vector<Query> traintime(K);
    for (int i=0;i<K;i++)
    {
        cin>>traintime[i].start;
        traintime[i].id=i;
    }

    sort(traintime.begin(),traintime.end(),cmp);
    int M;
    cin>>M;
    vector<vector<int>> passnager(M,vector<int>(2,0));
    for (int j=0;j<M;j++)
    {
        cin>>passnager[j][1]>>passnager[j][0];
    }
    sort(passnager.begin(),passnager.end());
    //MAIN
    int left=0;
    int right=0;
    vector<int> passnagerSum(K);
    vector<int> train(N);

    for (int t=0;t<K;t++)
    {
        left=traintime[t];
        right=traintime[t]+X;
        while (right < M &&passnager[right][0] < end)
        {

        }

    }



    //OUT
}