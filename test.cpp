#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int cur = a[0];
    int ans = a[0];

    for (int i = 1; i < a.size(); i++) {
        cur = max(a[i], cur + a[i]);
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}