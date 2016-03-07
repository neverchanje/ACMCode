#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ll INF = (1 << 30);

#define mset(arr, val) memset((arr), val, sizeof(arr))
#define for_r(i, s, t) for (int i = s; i < t + 1; i++)

const int maxn = 1001;

set<int> a, b;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n1, n2;
    int e1, e2;

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> e1;
        a.insert(e1);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> e2;
        b.insert(e2);
    }

    for (int e : a) {
        if (b.find(10000 - e) != b.end()) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
