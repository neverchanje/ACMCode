#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ll INF = (1 << 30);

#define mset(arr, val) memset((arr), val, sizeof(arr))
#define for_r(i, s, t) for (int i = s; i < t + 1; i++)

int m;
int main() {
    cin >> m;

    //   n / 5
    // + n / 25
    // + n / 125
    // + n / 625 ...

    vector<int> ans;

    for_r(n, 5, 500000) {
        ll tmp = n, sum = 0;
        while (tmp) {
            tmp /= 5;
            sum += tmp;
        }

        if (sum > m) {
            break;
        } else if (sum == m) {
            ans.push_back(n);
        }
    }
    cout << ans.size() << endl;
    for_r(i, 0, ans.size() - 1) cout << ans[i] << " ";
    cout << endl;
}
