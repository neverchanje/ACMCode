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

#define mset(arr) memset((arr), 0, sizeof(arr))
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

const int maxn = 502;
int n;
ll q;
ll tail[maxn][maxn];

int main() {
    // h
    // a1 a2 ... ah
    // a1 + a2 + ... + ah = n
    // a1 < a2 < ... < ah
    //
    cin >> n;

    mset(tail);

    REP(i, 1, n) tail[i][i] = 1;

    // tail[i][j] += tail[i-j][k] (j<i, k<j, k<=i-j)
    REP(i, 3, n) {
        REP(j, 2, i - 1) {
            REP(k, 1, min(i - j, j - 1)) { tail[i][j] += tail[i - j][k]; }
        }
    }

    ll ans = 0;
    REP(i, 2, n - 1) ans += tail[n][i];
    cout << ans << endl;
    return 0;
}
