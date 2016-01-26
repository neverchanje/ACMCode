#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 21;
const int MOD = 1e9 + 7;

#define rep(i, x, y) for (int i = x; i <= y; i++)
#define mset(arr) memset(arr, 0, sizeof(arr))

int n, ts;
int a[maxn], b[maxn], y[maxn];

int main() {
    ts = 1;
    while (cin >> n) {
        if (n == 0) break;

        printf("Case #%d:\n", ts++);

        for (int i = 0; i < n; i++) {
            cin >> y[i] >> a[i] >> b[i];
        }

        // (x-a) % (b-a) = y-a
        // x-a = (b-a)*k + y-a (k>=0)
        // x = y + (b-a)*k (k>=0)
        int k = 0, x;
        do {
            x = y[0] + (b[0] - a[0]) * k;
            bool can = true;
            for (int i = 1; i < n; i++) {
                if (x - a[i] < 0 || a[i] + (x - a[i]) % (b[i] - a[i]) != y[i]) {
                    can = false;
                    break;
                }
            }
            if (can) break;
            k++;
        } while (x < 10000);

        if (x < 10000) {
            printf("The actual year is %d.\n", x);
        } else {
            printf("Unknown bugs detected.\n");
        }
        printf("\n");
    }
    return 0;
}
