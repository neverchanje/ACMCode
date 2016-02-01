/*
 * 103.TrafficLights.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 3 * 1e5 + 2;

int n;
int a[maxn];
unordered_map<int, int> last;
int dp[maxn];  // dp[i] = maximum number of segments in range [0, i]
int match[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    memset(match, -1, sizeof(match));
    memset(dp, 0, sizeof(dp));
    last.reserve(maxn);  // NOTE

    last[a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        auto found = last.find(a[i]);
        if (found != last.end()) {
            int j = found->second;  // last[a[i]]
            if (dp[j - 1] + 1 > dp[i]) {
                match[i] = j;
                dp[i] = dp[j - 1] + 1;
            }
        }
        last[a[i]] = i;
    }

    if (dp[n] == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", dp[n]);

        int k = n + 1;
        int prev = n;
        while (k > 0) {
            k--;
            if (match[k] == -1) {
                continue;
            }
            int l = match[k];
            if (dp[l - 1] == 0) {
                printf("1 %d\n", prev);
                break;
            }
            printf("%d %d\n", l, prev);
            k = l;
            prev = l - 1;
        }
    }
}

// a[i] == a[j] and i<j
//
// if(dp[i-1] + 1 > dp[j])
//   add pair (i, j)
// dp[j] = max(dp[i-1] + 1, dp[j-1])
//
