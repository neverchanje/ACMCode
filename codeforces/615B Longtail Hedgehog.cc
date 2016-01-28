#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <bitset>
#include <memory>
#include <type_traits>

using namespace std;

const int maxn = 100001;
const int MOD = 1e9 + 7;

#define rep(i, x, y) for (int i = x; i <= y; i++)
#define mset(arr) memset(arr, 0, sizeof(arr))

int n, m;

vector<int> tb[maxn];
uint64_t dp[maxn];

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i <= n; i++) {
            dp[i] = 1;
            tb[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            tb[u].push_back(v);
            tb[v].push_back(u);
        }

        for (int u = 1; u <= n; u++) {
            for (int j = 0; j < tb[u].size(); j++) {
                int v = tb[u][j];
                if (v > u) {
                    dp[v] = max(dp[v], dp[u] + 1);
                }
            }
        }

        uint64_t ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(dp[i] * tb[i].size(), ans);
        }
        cout << ans << endl;
    }
    return 0;
}
