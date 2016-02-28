#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ll INF = (1 << 30);

ll n;
int w[21];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    ll ans = INF;
    ll g[2];
    for (ll x = 0; x < (1 << n); x++) {
        bitset<20> s(x);
        g[0] = g[1] = 0;

        for (int i = 0; i < n; i++) {
            if (s.test(i)) {
                g[0] += w[i];
            } else {
                g[1] += w[i];
            }
        }
        //        printf("%llu %llu\n", g[0], g[1]);
        ans = min(ans, abs(g[0] - g[1]));
    }
    cout << ans << endl;
}
