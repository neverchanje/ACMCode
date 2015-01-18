#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 10000010

int T, A, B, K, primacity[MAXN];
bool isPrim[MAXN];

int main(){
//	freopen("a.txt", "r", stdin);
//	freopen("b.txt", "w", stdout);

	for(int i=2; i<MAXN; i++) isPrim[i] = true;
	memset(primacity, 0, sizeof(primacity));

	for(int i=2; i<MAXN; i++)
	{
		if(!isPrim[i]) continue;
		for(int j=i; j<MAXN; j+=i)
		{
			if(j!=i)
				isPrim[j] = false;
			primacity[j]++;
		}
	}

	/*亲测超过7个质因子的数只有1个*/
	// for(int i=2; i<MAXN; i++)
	// {
	// 	if(primacity[i]>8)
	// 	{
	// 		printf("%d\n", i);
	// 	}
	// }

	cin>>T;
	for(int kase=1; kase<=T; kase++){
		printf("Case #%d: ", kase);
		cin>>A>>B>>K;

		if(K>8)
		{
			puts("0");
			continue;
		}

		int ans = 0;
		for(int i=A; i<=B; i++)
		{
			if(primacity[i]==K)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}