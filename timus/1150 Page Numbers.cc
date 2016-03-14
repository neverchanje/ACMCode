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

ll n;
int cnt[10];

void cal(ll v) {
    if (v / 10 == 0) {
        REP(i, 1, v) cnt[i]++;
        return;
    }

    cal(v / 10);

    REP(i, 0, 9) {
        cnt[i] *= 10;
        cnt[i] += v / 10 + 1;
    }
    cnt[0]--;

    int a[10];
    mset(a, 0);
    ll tmp = v / 10;
    while (tmp) {
        a[tmp % 10]++;
        tmp /= 10;
    }

    REP(i, v % 10 + 1, 9) cnt[i]--;
    REP(i, 0, 9) cnt[i] -= a[i] * (9 - v % 10);
}

int main() {
    cin >> n;
    mset(cnt, 0);
    cal(n);
    REP(i, 0, 9) cout << cnt[i] << endl;
    return 0;
}
