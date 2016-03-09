#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

ll s, x;

int main() {
    std::ios_base::sync_with_stdio(false);

    // a + b = a^b + ((a&b) << 1)
    // a&b = (s-x)/2

    cin >> s >> x;
    if (s < x || ((s - x) & 1)) {
        // no solution
        cout << 0 << endl;
        return 0;
    }

    ll d = (s - x) / 2, dp = 1;
    if (d & x) {
        cout << 0 << endl;
        return 0;
    }
    while (x) {
        if (x & 1) dp = dp * 2ll;
        x >>= 1;
    }
    if (d == 0) dp -= 2ll;
    cout << dp << endl;

    return 0;
}
