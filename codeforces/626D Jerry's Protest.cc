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

const int maxn = 2001;
const int maxv = 5001;
int n;
int a[maxn];
ll f1[maxv];
ll f2[maxv * 2];

int main() {
    std::ios_base::sync_with_stdio(false);

    // x1 + y1 + z1 < x2 + y2 + z2
    // x1 > x2
    // y1 > y2
    // z1 < z2
    //
    // f2(x1-x2+y1-y2)
    // f1(x1-x2)

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    mset(f1, 0);
    mset(f2, 0);
    rep(i, 0, n) rep(j, i + 1, n) { f1[a[j] - a[i]]++; }
    rep(i, 0, maxv) rep(j, 0, maxv) { f2[i + j] += f1[i] * f1[j]; }

    ll ans = 0, m = n * (n - 1) / 2;
    rep(j, 0, maxv) rep(i, 0, j) { ans += f2[i] * f1[j]; }
    printf("%.10lf\n", (double)ans / m / m / m);

    return 0;
}
