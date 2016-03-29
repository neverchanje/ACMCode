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
// const ll mod = 1000000007;
// const ll INF = (1 << 31LL);

const int maxn = 200002;
const int maxv = 1000002;
int n, m;
int a[maxn];
int p[maxn];

int main() {

  cin >> n >> m;

  mset(p);
  REP(i, 1, n) {
    cin >> a[i];
    if (i == 1 || a[i] == a[i - 1]) {
      p[i] = p[i - 1];
    } else {
      p[i] = i - 1;
    }
  }

  int l, r, x;
  while (m--) {
    scanf("%d %d %d", &l, &r, &x);
    if (a[r] != x) {
      printf("%d\n", r);
    } else {
      if (p[r] < l)
        printf("-1\n");
      else
        printf("%d\n", p[r]);
    }
  }
  return 0;
}
