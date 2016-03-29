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

ll n;
int main() {
  cin >> n;
  // 1+2+3+..+x <= n
  // (x+1)*x/2 = n
  //

  ll x = sqrt(2 * n);
  if ((x + 2) * (x + 1) / 2 < n)
    x++;
  if ((x + 1) * x / 2 >= n)
    x--;
  cout << n - (x + 1) * x / 2 << endl;
  return 0;
}
