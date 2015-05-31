#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 10004;
const ll MOD = 1000000007;
const int INF = 0xFFFFFFF;

#define rep(i, x, y) for (int i=x; i<=y; i++)
#define mset(arr) memset(arr, 0, sizeof(arr))  

int T, n;
ll m, k;

ll a[MAXN+4];

int main() {

//	freopen("a.in", "r", stdin);
//	freopen("b.out", "w", stdout);

	int index, flag;
	ll cur;

	cin>>T;
	for (int kase = 1; kase <= T; ++kase) {
		cin>>n>>m>>k;

		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
		}

		printf("Case #%d:\n", kase);
		sort(a, a+n);
		
		if (m < a[0]) {
			puts("madan!");
			continue;
		}

		if (m >= a[n-1]) {
			puts("why am I so diao?");
			continue;
		}

		flag = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] <= m)
				continue;

			assert(i>0);
			cur = a[i-1];
			index = i-1;
			break;
		}

		for (int i = index; i < n; ++i)
		{
			//cur + k >= a[index+1]
			if (cur + k >= a[i])
				continue;

			cur = a[i-1];

			if (k > 0) k--;

			if (cur + k < a[i]) {
				flag = false;
				break;
			}
			i--;
		}
		
		printf("%s\n", flag ? "why am I so diao?" : "madan!");
	}
	return 0;
}	

/**
 */