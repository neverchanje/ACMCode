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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ull;
typedef long long ll;

const int maxn = 500003;
int n;

vector<int> v[maxn];
vector<int> lv;

// a[i] = max(d[i], a[i-1]+1)
void dfs(int root, int pa, int dep) {
  if (v[root].size() == 1 && v[root][0] == pa) {
    // leaf node
    // but whose parent node is not 1
    if (pa != 1)
      lv.push_back(dep);
    return;
  }

  for (int to : v[root]) {
    if (to == pa)
      continue;
    dfs(to, root, dep + 1);
  }
}

void solve() {
  int rt = 1;

  int ans = 0, tmp;
  for (int to : v[rt]) {
    lv.clear();
    dfs(to, rt, 0);
    tmp = 0;
    sort(ALL(lv));
    for (int d : lv) {
      tmp = max(tmp + 1, d);
    }
    ans = max(ans, tmp + 1);
  }
  cout << ans << endl;
}

int main() {
  cin >> n;

  int x, y;
  rep(i, 0, n - 1) {
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }

  solve();
  return 0;
}
