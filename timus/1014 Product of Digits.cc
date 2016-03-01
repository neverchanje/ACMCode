#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ll INF = (1 << 30);

int n;
int main() {
    cin >> n;

    if (n == 0) {
        // positive integer required
        cout << 10 << endl;
        return 0;
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<char> ans;
    while (n != 1) {
        int p = 1;
        for (int i = 9; i >= 2; i--) {
            if (n % i == 0) {
                p = i;
                break;
            }
        }
        if (p == 1) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(p + '0');
        n /= p;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}
