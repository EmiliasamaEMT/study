#include <bits/stdc++.h>
using namespace std;

struct gd
{
    int d;
    int v;
    int p;
    bool type;
};
bool cmp_d(gd a, gd b)
{
    return a.d < b.d;
}
bool ctl_d(gd a,gd b)
{
    if (a.d>b.d)

   { return true;}
    else
    {
        return false;
    }
}
bool ctl_v(gd a,gd b)
{
    if (a.v>b.v)

    { return true;}
    else
    {
        return false;
    }
}
bool ctl(int a,int b)
{
    if (a>b)

    { return true;}
    else
    {
        return false;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<gd> task(n);

    vector<gd> must_task;
    vector<gd> regular_task;

    vector<int> c(m);
    for (int i=0;i<n;i++)
    {
        cin>>task[i].d>>task[i].v>>task[i].p;
        if (task[i].p==1)
        {
            task[i].type=true;
            must_task.push_back(task[i]);

        }
        else
        {
            task[i].type=false;
            regular_task.push_back(task[i]);

        }
    }
    for (int j =0;j<m;j++)
    {
        cin>>c[j];
    }
    //input

   // sort(must_task.begin(),must_task.end(),ctl_d);
   // sort(regular_task.begin(),regular_task.end(),ctl_v);
    //sort(c.begin(),c.end());
    // 都按照从小到大排序
    sort(c.begin(), c.end());
    sort(must_task.begin(), must_task.end(), cmp_d);
    long long sum = 0;

    // 保存没有被阻断单占用的工程师
    vector<int> remain;

    int j = 0;

    // -------------------------
    // 1. 先安排所有阻断单
    // -------------------------
    for (int i = 0; i < must_task.size(); i++)
    {
        // 当前工程师做不了阻断单
        while (j < m && c[j] < must_task[i].d)
        {
            remain.push_back(c[j]);
            j++;
        }

        // 找不到能完成阻断单的工程师
        if (j == m)
        {
            cout << -1 << endl;
            return 0;
        }

        // 使用当前工程师
        sum += must_task[i].v;
        j++;
    }

    // 剩余工程师
    while (j < m)
    {
        remain.push_back(c[j]);
        j++;
    }

    // -------------------------
    // 2. 再安排隐患单
    // -------------------------
    sort(regular_task.begin(), regular_task.end(), cmp_d);

    priority_queue<long long> pq;

    int k = 0;

    for (int i = 0; i < remain.size(); i++)
    {
        int skill = remain[i];

        // 当前工程师能够完成的任务都加入候选
        while (k < regular_task.size() &&
               regular_task[k].d <= skill)
        {
            pq.push(regular_task[k].v);
            k++;
        }

        // 选择价值最大的任务
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << endl;

    return 0;
}