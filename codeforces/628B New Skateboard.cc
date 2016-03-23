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

const int maxn = 3 * 100002;
char s[maxn];
ll dp[maxn];

int main() {
  ios_base::sync_with_stdio(false);

  cin >> (s + 1);
  int n = strlen(s + 1);
  REP(i, 1, n) {
    dp[i] = dp[i - 1];
    if (s[i] == '4' || s[i] == '8' || s[i] == '0') {
      dp[i]++;
      if ((s[i - 1] - '0') & 1)
        continue;
      // if not odd
      dp[i] += (i - 1);
      //  cout << "i: " << i << endl;
    } else if (s[i] == '2' || s[i] == '6') {
      if ((s[i - 1] - '0') & 1) {
        dp[i] += i - 1;
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}
