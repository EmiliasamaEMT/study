#include  <vector>
#include  <iostream>
#include  <string>
#include  <algorithm>
using namespace std;



int main() {
    string s;
    cin >> s;

    // 记录每个字符最后一次出现的位置
    vector<int> last(26, -1);

    for (int i = 0; i < s.size(); i++) {
        last[s[i] - 'a'] = i;
    }

    vector<int> ans;

    int start = 0;  // 当前片段起点
    int end = 0;    // 当前片段必须延伸到的最远位置

    for (int i = 0; i < s.size(); i++) {
        // 当前字符最后出现的位置可能让片段继续延长
        end = max(end, last[s[i] - 'a']);

        // 扫描位置追上当前片段最远边界，可以切段
        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }

    // 按题目样例格式输出，例如 [7, 1]
    cout << "[";

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << ans[i];
    }

    cout << "]" << endl;

    return 0;
}