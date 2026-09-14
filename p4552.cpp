#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
       cin >> a[i];
    }

    int cur = a[0];
    int ans = a[0];

    for (int i = 1; i < n; i++) {
        cur =max(a[i],a[i]+cur);
        ans =max(ans,cur);
    }

    cout <<ans << endl;

    return 0;
}