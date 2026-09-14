#include <iostream>
#include <vector>
using namespace std;

int M, N;
long long ans = 0;

// 是否已经占用某一列
vector<bool> col;

// 两个方向的斜线
vector<bool> diag1;
vector<bool> diag2;

// row：当前准备给第几行放监控器
void dfs(int row)
{
    // M行都成功放完，得到一种方案
    if (row == M)
    {
        ans++;
        return;
    }

    // 尝试把当前行的监控器放到每一列
    for (int c = 0; c < N; c++)
    {
        int d1 = row + c;
        int d2 = row - c + N - 1;

        // 同列或者同斜线，不能放
        if (col[c] || diag1[d1] || diag2[d2])
            continue;

        // 做选择：在(row, c)放一个监控器
        col[c] = true;
        diag1[d1] = true;
        diag2[d2] = true;

        // 继续处理下一行
        dfs(row + 1);

        // 回溯：撤销当前选择
        col[c] = false;
        diag1[d1] = false;
        diag2[d2] = false;
    }
}

int main()
{
    cin >> M >> N;

    col.resize(N, false);

    // 斜线编号范围都是 0 ~ M+N-2
    diag1.resize(M + N - 1, false);
    diag2.resize(M + N - 1, false);

    dfs(0);

    cout << ans << endl;

    return 0;
}