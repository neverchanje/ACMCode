/*
 * 620A.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

int x1, x2, y1, y2;
int main() {
    while (cin >> x1 >> y1 >> x2 >> y2) {
        cout << max(abs(x2 - x1), abs(y2 - y1)) << endl;
    }
}
