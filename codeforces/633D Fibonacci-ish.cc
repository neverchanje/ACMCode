#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
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

const int maxn = 1002;
ll a[maxn];
int n;
multiset<ll> s;
vector<ll> t;
map<pair<ll, ll>, ll> dp;

ll cal(ll x, ll y) {
  if (dp.find(make_pair(x, y)) != dp.end()) {
    return 0;
  }

  ll z, len = 2;
  s.erase(s.find(x));
  s.erase(s.find(y));
  t.push_back(x);
  t.push_back(y);
  dp[make_pair(x, y)] = 2;

  // dp[j][k] = max(dp[i][j]+1, dp[j][k]);
  // if dp[i][j] has been visited, continue.
  // if dp[j][k] has been visited, and dp[i][j] + 1 < dp[j][k]
  //    then the sequence will not move on.

  map<pair<ll, ll>, ll>::iterator it;
  while (s.find(x + y) != s.end()) {
    if ((it = dp.find(make_pair(y, x + y))) != dp.end() &&
        it->second >= len + 1)
      break;
    z = x + y;
    x = y;
    y = z;
    s.erase(s.find(z));
    t.push_back(z);
    dp[make_pair(x, y)] = ++len;
  }

  for (const auto &v : t)
    s.insert(v);
  t.clear();
  return len;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  rep(i, 0, n) {
    cin >> a[i];
    s.insert(a[i]);
  }

  ll ans = 0;

  rep(i, 0, n) rep(j, i + 1, n) {
    ans = max(ans, cal(a[i], a[j]));
    ans = max(ans, cal(a[j], a[i]));
  }
  cout << ans << endl;
  return 0;
}
