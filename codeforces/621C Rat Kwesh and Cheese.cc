/*
 * 621C.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100002;

int n, p;
int64_t l[maxn], r[maxn], ND[maxn], N[maxn];
int main() {
    cin >> n >> p;

    //
    // [li, ri]
    // Ni: ri - li + 1
    // Di: divisible by p
    // Di = ri/p - (li-1)/p
    // not divisible by p: NDi = Ni - Di
    //
    // [li, ri] [li+1, ri+1]
    //    si        si+1
    // si * si+1 not divisible by p: NDi * NDi+1
    //
    // pi = 1 - (ND[i] * ND[i+1])/(Ni * Ni+1)
    // expect = sum(pi)
    //
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        int64_t D = r[i] / p - (l[i] - 1) / p;
        ND[i] = (r[i] - l[i] + 1) - D;
        N[i] = r[i] - l[i] + 1;
    }

    double p, expect = 0;
    for (int i = 0; i < n; i++) {
        expect += 1 - double(ND[i]) / N[i] * ND[(i + 1) % n] / N[(i + 1) % n];
    }

    printf("%lf\n", expect * 2000);
    return 0;
}
