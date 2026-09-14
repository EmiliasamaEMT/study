#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> graph(1001);
    for(int i = 1; i <= n; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
}