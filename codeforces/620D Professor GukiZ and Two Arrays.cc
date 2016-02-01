/*
 * 620D.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int maxn = 2001;
int n, m;
int64_t a[maxn], b[maxn];

int64_t dp1[maxn * maxn];  // 2*(b[i1]-b[i2])
int64_t dp2[maxn * maxn];  // 2*(a[i1]-a[i2])
map<int64_t, pair<int, int> > vt;

int main() {
    int64_t sa = 0, sb = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sb += b[i];
    }

    // swap a[i], b[j]
    // v = |sum(a) - sum(b)|
    //
    // after 1 swap:
    // v = |(sum(a)-a[i]+b[j]) - (sum(b)-b[j]+a[i])|
    // v = |sum(a)-sum(b) + 2*(b[j]-a[i])|
    //
    // after 2 swaps:
    // v = |sum(a)-sum(b) + 2*(b[j1]-a[i1]) + 2*(b[j2]-a[i2])|
    // i1 != i2, j1 != j2
    // v = |sum(a)-sum(b) + 2*(b[j1]+b[j2]) - 2*(a[i1]+a[i2])|
    //

    int64_t minv = abs(sa - sb);
    vector<pair<int, int> > ans;
    int64_t val;

    // after 1 swap:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            val = abs(sa - sb + 2ll * b[j] - 2ll * a[i]);
            if (val < minv) {
                ans.clear();
                ans.push_back(make_pair(i, j));
                minv = val;
            }
        }
    }

    // after 2 swaps:
    if (n > 1 && m > 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vt[2ll * (a[i] + a[j])] = make_pair(i, j);
            }
        }

        int64_t p1, p2;

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                p1 = sa - sb + 2ll * (b[i] + b[j]);
                auto it = vt.lower_bound(p1);
                if (it != vt.begin()) it--;  // the last

                for (int k = 0; k < 2; k++) {
                    if (it == vt.end()) break;
                    p2 = it->first;
                    val = abs(p1 - p2);
                    if (val < minv) {
                        ans.clear();
                        ans.push_back(make_pair(it->second.first, i));
                        ans.push_back(make_pair(it->second.second, j));
                        minv = val;
                    }
                    it++;
                }
            }
        }
    }

    cout << minv << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}
