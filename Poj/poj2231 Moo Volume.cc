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

const int maxn = 10002;

int n;
ll pos[maxn];
ll sum[maxn];
ll rsum[maxn];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;

    REP(i, 1, n) cin >> pos[i];
    sort(pos + 1, pos + n + 1);

    sum[0] = 0;
    REP(i, 1, n) { sum[i] = sum[i - 1] + pos[i]; }
    ll ans = 0;
    REP(i, 1, n) {
        ans += pos[i] * (i - 1) - sum[i - 1] + (sum[n] - sum[i]) -
               (n - i) * pos[i];
    }
    cout << ans << endl;

    return 0;
}
