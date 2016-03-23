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

const int maxn = 100002;
char s[maxn], a[maxn];
int n, k;

int main() {
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  cin >> s;
  rep(i, 0, n) {
    int x = s[i] - 'a';
    int y = 'z' - s[i];
    int add = x > y ? -x : y;
    if (abs(add) > k) {
      add = (add > 0 ? +1 : -1) * k;
    }
    a[i] = s[i] + add;
    assert(a[i] <= 'z' && a[i] >= 'a');
    k -= abs(add);
  }
  if (k > 0)
    cout << -1 << endl;
  else
    cout << a << endl;
  return 0;
}
