#include<bits/stdc++.h>

using namespace std;


int main()
{
    int N;
    cin >> N;

    // 吃掉 cin >> N 后剩余的换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // lines[i]：第 i 条地铁线有哪些站
    vector<vector<string>> lines(N);

    // stationLines["B"]：B站属于哪些线路
    map<string, vector<int>> stationLines;

    // 读取 N 条线路
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);

        // 把一整行按照空格拆成一个个站名
        stringstream ss(line);

        string station;

        while (ss >> station)
        {
            lines[i].push_back(station);

            // 记录这个站属于第 i 条线路
            stationLines[station].push_back(i);
        }
    }

    // 起点和终点
    string start, target;
    cin >> start >> target;

    // 起点或终点不存在
    if (stationLines.find(start) == stationLines.end() ||
        stationLines.find(target) == stationLines.end())
    {
        cout << "NA" << endl;
        return 0;
    }

    // dist[i]：
    // 从起点所在的线路，到第 i 条线路最少换乘几次
    vector<int> dist(N, -1);

    // parent[i]：
    // 到达第 i 条线路之前在哪条线路
    vector<int> parent(N, -1);

    // transfer[i]：
    // 是在哪个站换乘到第 i 条线路的
    vector<string> transfer(N);

    // 标记哪些线路包含终点
    vector<bool> isTargetLine(N, false);

    for (int lineId : stationLines[target])
    {
        isTargetLine[lineId] = true;
    }

    // BFS队列中存“线路编号”
    queue<int> q;

    // 起点可能属于多条线路
    // 都可以作为 BFS 起点，而且还没有发生换乘
    for (int lineId : stationLines[start])
    {
        dist[lineId] = 0;
        q.push(lineId);
    }

    // 某个换乘站一旦扩展过，就不用重复扩展
    map<string, bool> usedStation;

    int endLine = -1;

    // BFS
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 当前线路包含终点
        if (isTargetLine[cur])
        {
            endLine = cur;
            break;
        }

        // 遍历当前线路的所有站
        for (string station : lines[cur])
        {
            // 这个站已经用于寻找换乘线路了
            if (usedStation[station])
                continue;

            usedStation[station] = true;

            // stationLines[station]
            // 表示经过这个站的所有线路
            for (int nextLine : stationLines[station])
            {
                // 已经访问过这条线路
                if (dist[nextLine] != -1)
                    continue;

                // 换乘一次
                dist[nextLine] = dist[cur] + 1;

                // 记录路径
                parent[nextLine] = cur;
                transfer[nextLine] = station;

                q.push(nextLine);
            }
        }
    }

    // 没有找到方案
    if (endLine == -1)
    {
        cout << "NA" << endl;
        return 0;
    }

    // =========================
    // 恢复换乘路径
    // =========================

    vector<string> transfers;

    int cur = endLine;

    while (parent[cur] != -1)
    {
        // 到达当前线路时所经过的换乘站
        transfers.push_back(transfer[cur]);

        // 回到上一条线路
        cur = parent[cur];
    }

    // 刚才是从终点往起点倒着找的
    reverse(transfers.begin(), transfers.end());

    // 输出：起点-换乘站1-换乘站2-终点
    cout << start;

    for (string station : transfers)
    {
        cout << "-" << station;
    }

    cout << "-" << target << endl;

    // 单线路票价2元，每换乘一次+1
    cout << 2 + transfers.size() << endl;

    return 0;
}
