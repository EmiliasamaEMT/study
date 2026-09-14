#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> cnt;

    // 1. 读入并统计每个号码出现次数
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[______]++;
    }

    vector<int> n1;
    vector<int> n2;
    vector<int> single;

    // 2. 遍历所有不同号码
    for (auto p : cnt) {
        int num = p.first;    // 号码
        int times = p.second; // 出现次数

        // 出现超过2次，无解
        if (times > 2) {
            cout << "null" << endl;
            return 0;
        }

        // 出现2次：两队各放一个
        if (times == 2) {
            n1.push_back(______);
            n2.push_back(______);
        }

        // 出现1次：先收集起来
        else if (times == 1) {
            single.push_back(______);
        }
    }

    // 3. 单次出现的号码从小到大排序
    sort(single.begin(), single.end());

    int target = n / 2;  // 每队人数

    // n1还缺多少人
    int need = target - n1.size();

    // 4. 较小的单次号码给n1，其余给n2
    for (int i = 0; i < single.size(); i++) {
        if (i < need) {
            n1.push_back(______);
        } else {
            n2.push_back(______);
        }
    }

    // 5. 最终排序
    sort(n1.begin(), n1.end());
    sort(n2.begin(), n2.end());

    // 6. 输出
    for (int x : n1) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : n2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}//
// Created by yxy on 2026/9/9.
//