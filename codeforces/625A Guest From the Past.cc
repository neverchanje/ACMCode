/*
 * 625A.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll n, a, b, c;

int main() {
    // n, a, b, c
    cin >> n >> a >> b >> c;

    ll g = 0, p = 0;

    if (a > b - c) {
        if (n - c > 0) g = (n - c) / (b - c);
        if (n - g * (b - c) > 0) p = (n - g * (b - c)) / a;
    } else {
        // a <= b - c
        p = n / a;
    }
    cout << p + g << endl;
}
