#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX=10001;  

#define rep(i, x, y) for (int i=x; i<=y; i++)
#define mset(arr) memset(arr, 0, sizeof(arr))  

int T;
char road[52], str[30];
int digit[10];

void solve(int first, int last, int interval) {
	for (int i = first; i <= last; i+=interval) {
		int single = i;
		while(single) {
			digit[single % 10]++;
			single /= 10;
		}
	}
}

int main()  
{
	freopen("a.in", "r", stdin);

	scanf("%d", &T);
	getchar();

	while(T--) {

		cin.getline(road, 50, '\n');

		memset(digit, 0, sizeof(digit));

		int nhouse;
		char adresss[10];	
		scanf("%d %s", &nhouse, adresss);
		getchar();

		int num = nhouse, single, first, last, interval;
		while (num>0) {
			cin.getline(str, 30, '\n');
			if (str[0] == '+') {
				sscanf(str+1, " %d %d %d", &first, &last, &interval);
				solve(first, last, interval);
				num -= (last - first) / interval + 1;
			} else {
				sscanf(str, "%d", &single);
				while(single) {
					digit[single % 10]++;
					single /= 10;
				}
				num--;
			}
		}

		puts(road);
		printf("%d %s\n", nhouse, adresss);		
		int total = 0;
		for (int i = 0; i < 10; ++i) {
			printf("Make %d digit %d\n", digit[i], i);
			total += digit[i];
		}
		printf("In total %d digit%s\n", total, (total==1) ? "" : "s");
	}
    return 0;  
}	