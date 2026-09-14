#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int n,m,k;
    int ans=0;
    cin>>n>>m>>k;
    vector<vector<int>> graph(1001);
    for(int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    vector<int> dis(1001,-1);
    queue<int> q;
    q.push(m);
    dis[m]=0;
    while (q.size()!=0)
    {
        int x=q.front();
        q.pop();

        if (dis[x]==k)
            continue;
        for (int y:graph[x])
        {
            if (dis[y]!=-1)
                continue;
            dis[y]=dis[x]+1;
            ans++;
            q.push(y);
        }
    }
    cout<<ans;
}