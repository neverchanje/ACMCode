#include <algorithm>
#include <bitset>
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

// const int maxn = 100002;

int hh, mm, a;

int main() {
  // scanf("%d:%d\n", &hh, &mm);
  // scanf("%d\n", &a);
  cin >> hh;
  getchar();
  cin >> mm;
  cin >> a;

  mm += a;
  hh += mm / 60;
  mm -= mm / 60 * 60;
  hh -= hh / 24 * 24;

  printf("%02d:%02d\n", hh, mm);
  return 0;
}
