#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int T, N, A, B;
const int maxn = 2010;
const int MOD = 1e9+7;
long long dp[maxn*2][maxn];

int main(){
//	freopen("a.txt", "r", stdin);
//	freopen("b.txt", "w", stdout);
	cin>>T;
	for(int kase=1; kase<=T; kase++)
	{
		printf("Case #%d: ", kase);
		scanf("%d-%d", &A, &B);
		memset(dp, 0, sizeof(dp));

		//stressful
		dp[1][0] = 1;
		for(int k=2; k<=A+B; k++)
		{
			for(int x=0; x<=min(A, k); x++)
			{
				int y = k-x;
				if (y<B && y<x)
					break;
				if( y-1>=B || x<=y-1)
					dp[k][x] = (dp[k][x] + dp[k-1][x]) % MOD;
				if(x>0)
					dp[k][x] = (dp[k][x] + dp[k-1][x-1]) % MOD;
			}
		}

		// for(int k=0; k<=A+B; k++)
		// 	for(int x=0; x<=min(A, k); x++)
		// 		printf("dp[%d][%d]=%d\n", k, x, dp[k][x]);

		long long stressful = dp[A+B][A] % MOD;
		
		//stressfree
		memset(dp, 0, sizeof(dp));
		dp[1][1] = 1;
		for(int k=2; k<=A+B; k++){
			for(int x=k/2; x<=min(A, k); x++)
			{
				int y = k-x;
				if(x<=y) continue;
				dp[k][x] = (dp[k][x] + dp[k-1][x]) % MOD;
				if(x-1>y && x>0) dp[k][x] = (dp[k][x] + dp[k-1][x-1]) % MOD;
			}
		}
		long long stressfree = dp[A+B][A] % MOD;
		cout<<stressfree<<" "<<stressful<<endl;
	}
	return 0;
}