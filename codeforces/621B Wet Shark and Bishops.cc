/*
 * 621B.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1002;

int n;
int64_t pos[maxn * 2];  // y = x + k, pos[k+1000] += 1; k = [-1000, +1000]
int64_t neg[maxn * 2];  // y = -x + k, neg[k] += 1; k = [0, 2000]

int main() {
    cin >> n;

    memset(pos, 0, sizeof(pos));
    memset(neg, 0, sizeof(neg));

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pos[y - x + 1000]++;
        neg[y + x]++;
    }

    int64_t ans = 0;
    for (int i = 0; i <= 2 * 1000; i++) {
        if (pos[i] > 1) {
            ans += pos[i] * (pos[i] - 1) / 2;
        }
        if (neg[i] > 1) {
            ans += neg[i] * (neg[i] - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
