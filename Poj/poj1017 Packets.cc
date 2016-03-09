#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

#define mset(arr, val) memset((arr), val, sizeof(arr))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ull;
typedef long long ll;
const ll mod = 1000000007;

const int maxn = 200005;

int s[7];
int main() {
    std::ios_base::sync_with_stdio(false);

    while (cin >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6]) {
        if (s[1] + s[2] + s[3] + s[4] + s[5] + s[6] == 0) break;

        ll ans = 0;

        ans += s[6];

        ans += s[5];
        s[1] -= s[5] * 11;

        ans += s[4];
        s[2] -= s[4] * 5;

        ans += s[3] / 4 + 1;
        s[3] = s[3] % 4;

        switch (s[3]) {
            case 1:
                s[2] -= 5;
                s[1] -= 7;
                break;
            case 2:
                s[2] -= 3;
                s[1] -= 6;
                break;
            case 3:
                s[2] -= 1;
                s[1] -= 5;
                break;
            default:
                ans--;  // no more block needed.
                break;
        };
        if (s[2] < 0) {
            // overdrawn from s[2]
            s[1] -= -s[2] * 4;
            s[2] = 0;
        }

        if (s[1] < 0) {
            // overdrawn from s[1]
            s[1] = 0;
        }

        ans += ceil((s[1] + 4 * s[2]) / 36.0);
        cout << ans << endl;
    }
    return 0;
}
