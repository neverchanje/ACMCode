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
#define PER(i, a, n) for (int i = n; i >= a; i--)
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
const ll mod = 1000000007;
// const ll INF = (1 << 31LL);

const int maxm = 200002;

int m;
ll n;
ll p[maxm], a[maxm];
ll F, D;

// calculate base^expo
ll binPow(ll base, ll expo) {
  ll res = 1;
  while (expo) {
    if (expo & 1) {
      res = res * base % mod;
    }
    expo /= 2;
    base = base * base % mod;
  }
  return res;
}

int main() {
  cin >> m;
  n = 1;
  rep(i, 0, m) { cin >> p[i]; }

  // d(n), the number of divisors of n
  // n = p1^x1 + p2^x2 + p3^x3 ... + pk^xk
  // d(n) = (x1+1) * (x2+1) * (x3+1) * ... * (xk+1)
  //
  // statement 1. d(ab) = d(a) * d(b)
  // statement 2. f(n) = n^(D(n)/2)
  // statement 3. f(p^k) = p^(k*(k+1)/2)
  // statement 4. f(ab) = f(a)^d(b) * f(b)^d(a)
  //
  // let D(i) = (a1+1) * (a2+1) * ... * (ai+1) = D(i-1) * (ai+1)
  // thus F(i) = f(p1^a1 * p2^a2 * ... * pi^ai)
  //           = F(i-1)^(ai+1) * f(pi^ai)^D(i-1)
  //
  // since a^x = a^(x%(m-1)) (mod m)
  // D(i) = D(i-1) * (ai+1) % (m-1)
  //
  mset(a);
  rep(i, 0, m) { a[p[i]]++; }
  sort(p, p + m);
  m = unique(p, p + m) - p;
  F = 1;
  D = 1;
  rep(i, 0, m) {
    F = binPow(F, a[p[i]] + 1) *
        binPow(binPow(p[i], a[p[i]] * (a[p[i]] + 1) / 2), D) % mod;
    D = D * (a[p[i]] + 1) % (mod - 1);
  }
  cout << F << endl;
  return 0;
}
