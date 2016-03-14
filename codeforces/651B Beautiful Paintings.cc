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

const int maxn = 1002;
int n;
set<int> sa;
multiset<int> sb;

int main() {
    cin >> n;

    int va;
    rep(i, 0, n) {
        cin >> va;
        sb.insert(va);
    }

    ll ans = 0;
    while (!sb.empty()) {
        sa.clear();
        for (int v : sb) sa.insert(v);
        ans += sa.size() - 1;
        for (int v : sa) sb.erase(sb.find(v));
    }
    cout << ans << endl;
    return 0;
}
