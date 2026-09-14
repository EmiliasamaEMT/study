#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int startX, startY;
    int targetX, targetY;

    cin >> startX >> startY;
    cin >> targetX >> targetY;

    int k;
    cin >> k;

    // blocked[y][x] = true 表示该位置是障碍
    vector<vector<bool>> blocked(n, vector<bool>(m, false));

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        blocked[y][x] = true;
    }

    // dist[y][x] 表示起点到该位置的最短距离
    // -1 表示还没有访问过
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> q;

    // 起点入队
    q.push({startX, startY});
    dist[startY][startX] = 0;

    // 上、下、左、右
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        // 取出队首
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 如果已经到终点
        if (x == targetX && y == targetY)
        {
            cout << dist[y][x] << endl;
            return 0;
        }

        // 尝试四个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 越界
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            // 障碍
            if (blocked[ny][nx])
                continue;

            // 已经访问过
            if (dist[ny][nx] != -1)
                continue;

            // 更新最短距离
            dist[ny][nx] = dist[y][x] + 1;

            // 加入队列
            q.push({nx, ny});
        }
    }

    // BFS结束仍没找到终点
    cout << -1 << endl;

    return 0;
}