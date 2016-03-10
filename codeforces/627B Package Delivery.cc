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

int n, a, b, k, q;

// fenwick tree / binary indexed tree
ll prefix[maxn];
ll postfix[maxn];

inline int lowbit(int x) { return x & (-x); }

inline ll sum(ll *C, int x) {
    ll ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

inline void add(ll *C, int x, int d) {
    while (x <= n) {
        C[x] += d;
        x += lowbit(x);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    // init
    mset(prefix, 0);
    mset(postfix, 0);

    cin >> n >> k >> a >> b >> q;
    REP(i, 1, q) {
        int type, x, y;
        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            // prefix[x] = min(prefix[x]+y, b);
            ll cur = sum(prefix, x) - sum(prefix, x - 1);
            add(prefix, x, cur + y > b ? b - cur : y);

            // postfix[n-x+1] = min(post[n-x+1]+y, a);
            cur = sum(postfix, n - x + 1) - sum(postfix, n - x);
            add(postfix, n - x + 1, cur + y > a ? a - cur : y);
        } else {  // type == 2
            cin >> x;
            // di, di + 1, di + 2, ... di + k - 1
            ll ans =
                sum(prefix, x - 1) + sum(postfix, n - min(x + k, n + 1) + 1);
            cout << ans << endl;
        }
    }

    return 0;
}
