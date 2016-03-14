#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

#define mset(arr, val) memset((arr), val, sizeof(arr))
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
const ll mod = 1000000007;

int a1, a2;
int main() {
    cin >> a1 >> a2;

    int count = 1;
    while (a1 > 0 && a2 > 0) {
        if (a1 > a2) swap(a1, a2);

        if (a2 == 1) break;
        a1 += 1;
        a2 -= 2;

        count++;
    }
    cout << count - 1 << endl;
    return 0;
}
