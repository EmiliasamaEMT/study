#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> graph;
vector<int> weight;
vector<string> name;
vector<bool> visited;

int sum;
int maxNode;

// DFS：遍历当前整个连通网络
void dfs(int u) {
    visited[u] = true;

    // 当前网络权重累加
    sum += weight[u];

    // 找当前网络中权重最大的节点
    if (weight[u] > weight[maxNode]) {
        maxNode = u;
    }

    // 遍历所有邻居
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    name.resize(n);
    weight.resize(n);

    map<string, int> id;

    // 读取节点名称和权重
    for (int i = 0; i < n; i++) {
        cin >> name[i] >> weight[i];

        // 节点名称 -> 节点编号
        id[name[i]] = i;
    }

    graph.resize(n);

    int m;
    cin >> m;

    // 读取连接关系
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        int u = id[a];
        int v = id[b];

        // 无向图，两边都要添加
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.assign(n, false);

    int bestSum = -1;
    int bestNode = -1;

    // 寻找所有连通网络
    for (int i = 0; i < n; i++) {

        if (visited[i]) {
            continue;
        }

        // 开始统计一个新的连通网络
        sum = 0;
        maxNode = i;

        dfs(i);

        // 当前网络比之前的最大网络更大
        if (sum > bestSum) {
            bestSum = sum;
            bestNode = maxNode;
        }
    }

    cout << name[bestNode] << " " << bestSum << endl;

    return 0;
}