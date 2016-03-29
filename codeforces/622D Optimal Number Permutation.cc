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

const int maxn = 500003;
int n;
int a[maxn * 2];

int main() {
  cin >> n;

  mset(a);

  REP(i, 1, n - 1) {
    if (i < n - i + 1) {
      a[i] = a[n - i + 1] = 2 * i - 1;
    }
    if (n + i < 2 * n - i) {
      a[i + n] = a[2 * n - i] = 2 * i;
    }
  }
  REP(i, 1, 2 * n) {
    if (a[i] == 0)
      a[i] = n;
  }

  REP(i, 1, 2 * n) { cout << a[i] << " "; }
  cout << endl;

  return 0;
}
