#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

const int maxn = 21;
const int MOD = 1e9 + 7;

#define rep(i, x, y) for (int i = x; i <= y; i++)
#define mset(arr) memset(arr, 0, sizeof(arr))

int64_t n;
const int dir[6][2] = {{-1, 2}, {-2, 0}, {-1, -2}, {1, -2}, {2, 0}, {1, 2}};

int main() {
    while (cin >> n) {
        // the first circle = 6
        // the second circle = 12
        // the nth circle = 6*n
        //
        // On the end of nth circle, the number of moves is
        // 6 + 6*2 + ... + 6*n
        // = 6n*(n+1)/2
        // = 3n*(n+1)
        //
        // On the nth move, we are on the mth circle.
        // 3m*(m-1) < n <= 3m*(m+1) (m>=1, n>=1)
        //
        // binary search the result m
        //
        if (n == 0) {
            printf("0 0\n");
            continue;
        }

        int64_t l = 0, r = 1e9;
        int64_t m;
        while (r - l > 1) {
            m = (r + l) / 2;
            if (3 * m * (m - 1) >= n) {
                r = m;
            } else if (3 * m * (m + 1) < n) {
                l = m;
            } else {
                // 3m*(m-1) < n <= 3m*(m+1)
                break;
            }
        }

        int64_t d = n - 3 * m * (m - 1);
        int64_t i = 0;
        int64_t x = 2 * m, y = 0;
        while (d) {
            if (d > m) {
                d -= m;
                x += m * dir[i][0];
                y += m * dir[i][1];
                i++;
            } else {
                x += d * dir[i][0];
                y += d * dir[i][1];
                break;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
