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

// trie
const int maxnode = 1111111;
int ch[maxnode][26] = {0};
int val[maxnode] = {0};
int ndtot = 1, rt = 0;
void insert(const char *s, int v) {
    int u = rt;
    for (int i = 0; s[i]; i++) {
        int c = tolower(s[i]) - 'a';
        if (!ch[u][c]) {
            ch[u][c] = ndtot++;
        }
        u = ch[u][c];
    }
    val[u] = v;
}

const int N = 10002;
const int W = 1002;
const int M = 100002;

int n, m;
char text[N];
string word[M];
int dp[N];

int main() {
    std::ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> text;
    cin >> m;
    REP(i, 1, m) {
        cin >> word[i];
        insert(word[i].c_str(), i);
    }

    int u = rt;
    per(i, 0, n) {
        int c = text[i] - 'a';
        if (!ch[u][c]) break;
        u = ch[u][c];
        if (val[u]) dp[i] = val[u];
    }

    // in reverse order
    per(i, 0, n) {
        if (!dp[i]) continue;
        //        cout << "i: " << i << " dp: " << word[dp[i]] << endl;
        u = rt;
        per(k, 0, i) {
            int c = text[k] - 'a';
            if (!ch[u][c]) break;
            u = ch[u][c];
            if (val[u]) dp[k] = val[u];
        }
    }

    int cur = 0;
    while (text[cur]) {
        cout << word[dp[cur]] << " ";
        cur = cur + word[dp[cur]].length();
    }
    cout << endl;
    return 0;
}
