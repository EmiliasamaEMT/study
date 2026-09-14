#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
int n;
cin>>n;
for(int i=1;i<=n;i++){
vector<int> used(n, 0);
cin>>used[i,0];
}
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pvs(n);
    for (int i = 0; i < n; i++) {
        cin >> pvs[i];
    }

    // optimizer[i] = 1 表示位置 i 已安装优化器
    vector<int> optimizer(n, 0);

    int ans = 0;

    for (int i = 0; i < n; i++) {

        // 当前位置不是光伏板，不需要处理
        if (pvs[i] == 0) {
            continue;
        }

        // 判断当前光伏板是否已经被优化器覆盖
        bool covered = false;

        if (i > 0 && optimizer[i - 1] == 1) {
            covered = true;
        }

        if (i + 1 < n && optimizer[i + 1] == 1) {
            covered = true;
        }

        // 已经覆盖，直接处理下一个
        if (covered) {
            continue;
        }

        // 没覆盖：优先在右边放优化器
        if (i + 1 < n && pvs[i + 1] == 0) {
            optimizer[i + 1] = 1;
            ans++;
        }
        // 右边不能放，再尝试左边
        else if (i > 0 && pvs[i - 1] == 0) {
            optimizer[i - 1] = 1;
            ans++;
        }
        // 左右都没空位，无解
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}