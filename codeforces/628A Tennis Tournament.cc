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
int n, b, p;
int main() {
  cin >> n >> b >> p;

  ll totb = 0, totp = p * n;
  while (n > 1) {
    int k = 1;
    while (true) {
      if (k * 2 > n)
        break;
      k *= 2;
    }
    totb += k * b + k / 2;
    n = k / 2 + n - k;
  }
  cout << totb << " " << totp << endl;
  return 0;
}
