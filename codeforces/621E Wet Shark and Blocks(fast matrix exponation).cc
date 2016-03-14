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

const int maxn = 50002;
const int maxx = 102;
int n, b, k, x;
int a[maxn];
int cnt[10];

ll mat[maxx][maxx];
ll res[maxx][maxx];
ll base[maxx][maxx];

// a = a * b
void mul(ll a[maxx][maxx], ll b[maxx][maxx]) {
    mset(res);
    REP(i, 0, x - 1) {
        REP(j, 0, x - 1)
        REP(k, 0, x - 1)
        res[i][k] = (res[i][k] + a[i][j] * b[j][k]) % mod;
    }
    REP(i, 0, x - 1) REP(j, 0, x - 1) a[i][j] = res[i][j];
}

int main() {
    // fast matrix exponation
    //
    // - dp[i][(10*t+a[j])%x] += dp[i-1][t]
    //
    // final solution:
    // - mat[T][(10*T+j)%x] += cnt[j]
    //   mat[T1][T2] = mat[T1][T2]^b
    //   answer = mat[0][k]

    cin >> n >> b >> k >> x;

    mset(cnt);
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    mset(mat);
    REP(T, 0, x - 1) { REP(j, 0, 9) base[T][(10 * T + j) % x] += cnt[j]; }

    // identity matrix
    REP(i, 0, x - 1) mat[i][i] = 1;

    ll ex = b;
    while (ex) {
        if (ex & 1) {
            mul(mat, base);
        }
        mul(base, base);
        ex >>= 1;
    }

    cout << mat[0][k] << endl;
    return 0;
}
