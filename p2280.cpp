#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> cnt(65536, 0);
    int n,x,ans=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
                if (x > 0 && cnt[x - 1] > 0) {
                    // 接到一个以 x-1 结尾的发送源后面
                    cnt[x - 1]--;
                    cnt[x]++;
                }
                else {
                    // 没有可以接的，只能新建发送源
                    ans++;
                    cnt[x]++;
                }

    }
    cout << ans << endl;
}


