/*
 * 620B.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>

using namespace std;

int digit[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int seg[1000001];  // brute force

int ans, a, b;

int main() {
    seg[0] = digit[0];
    for (int i = 1; i <= 1000000; i++) {
        int x = i;
        seg[i] = 0;
        while (x) {
            seg[i] += digit[x % 10];
            x /= 10;
        }
        seg[i] += seg[i - 1];
    }

    cin >> a >> b;
    // a<b
    if (a >= b) swap(a, b);

    // ans = f(b) - f(a-1)
    // f(x): segments from 0 to x

    int fa, fb;
    if (a == 0) {
        cout << seg[b] << endl;
    } else {
        cout << seg[b] - seg[a - 1] << endl;
    }

    return 0;
}
