/*
 * 621A.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100002;

int n;
int a[maxn];

int main() {
    scanf("%d", &n);

    int64_t sa = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sa += a[i];
    }

    sort(a, a + n);
    if (sa & 1) {
        // find the minimum odd integer
        for (int i = 0; i < n; i++) {
            if (a[i] & 1) {
                sa -= a[i];
                break;
            }
        }
    }
    cout << sa << endl;
}
