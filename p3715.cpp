#include <bits/stdc++.h>
using namespace std;
// 判断：最多新增 k 个机房，能不能让所有城市服务质量都 >= mid
bool check(const vector<long long>& base,
           int n, int r,
           long long k,
           long long mid)
{
    // diff[i]：
    // 扫描到城市 i 时，新增机房带来的覆盖量要变化多少
    vector<long long> diff(n + 1, 0);

    long long add = 0;   // 当前城市受到的新增机房覆盖量
    long long used = 0;  // 已经新增了多少个机房

    for (int i = 0; i < n; i++)
    {
        // 处理之前新增机房在这里的失效
        add += diff[i];

        // 当前城市实际服务质量
        long long current = base[i] + add;

        // 当前城市还达不到 mid
        if (current < mid)
        {
            long long need = mid - current;

            used += need;

            // 新增机房数量超过 k
            if (used > k)
            {
                return false;
            }

            // 贪心：
            // 为了尽量帮助右边未来的城市，
            // 把这 need 个机房放到能覆盖 i 的最右位置
            int pos = min(n - 1, i + r);

            // 这些机房最远能影响到的城市
            int end = min(n - 1, pos + r);

            // 当前城市立刻受到影响
            add += need;

            // 从 end + 1 开始，这批新增机房失效
            if (end + 1 < n)
            {
                diff[end + 1] -= need;
            }
        }
    }

    return true;
}

int main() {
    int n,r,k;
    cin>>r>>k>>n;
    vector<int> cities(n);
    vector<int> base(n);
    vector<int> count(n+1,0);
    for(int i=0;i<n;i++)
        {
        cin>>cities[i];
        count[i+1]+=cities[i]+count[i];
    }
    int maxbase=0;
    for(int i=0;i<n;i++) {
        base[i]=count[min(n-1,i+r)+1]-count[max(0,i-r)];
        maxbase=max(maxbase,base[i]);
    }


    // n        = 城市数量
    // r        = 覆盖半径
    // k        = 最多可新建机房数量
    //
    // cities[i]
    //          = 第 i 个城市原有机房数量
    //


    // base[i]
    //          = 第 i 个城市原始服务质量
    //
    int mid;
    mid=maxbase / 2;
    int used=0;
    int add=0;
    vector<int> diff(n,0);
    for(int i=0;i<n;i++) {

        add += diff[i]

   ② 算当前城市实际服务质量
      current = base[i] + add

   ③ 如果 current < mid:
          need = mid-current

          used += need

          如果 used > k:
              return false

          ④ 把 need 个机房放在
             min(n-1, i+r)

          ⑤ 这些新增机房会继续影响后面的城市
             更新 add 和 diff

    }
    // mid
    //          = 当前二分假设的最低服务质量
    //
    // used
    //          = check(mid) 过程中已经新建了多少机房
    //
    // add = 当前城市范围内新增机房数量
    // diff[i] =第i处机房影响到的最右边的位置
    // current =当前城市实际服务质量
    // need =当前城市实际服务质量比mid小多少
    //
    //
    // used = 0
    // add = 0
    //
    // for i = 0 到 n-1:
    //
    //     ① 处理在 i 位置失效的额外覆盖
    //        add += diff[i]
    //
    //     ② 算当前城市实际服务质量
    //        current = base[i] + add
    //
    //     ③ 如果 current < mid:
    //            need = mid-current
    //
    //            used += need
    //
    //            如果 used > k:
    //                return false
    //
    //            ④ 把 need 个机房放在
    //               min(n-1, i+r)
    //
    //            ⑤ 这些新增机房会继续影响后面的城市
    //               更新 add 和 diff
    //
    // return true
}