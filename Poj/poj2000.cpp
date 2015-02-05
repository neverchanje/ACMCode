#include <iostream>
#include <cstdio>
using namespace std;

int n;

int main(){
//	freopen("a.txt", "r", stdin);
	while(cin>>n){
		if(n==0) break;
		printf("%d ", n);

		int d=1;
		long long ans=0;
		for(; d<=n; d++)
		{
			if(d*(d+1)/2 >= n)
				break;
			ans += d*d;
		}

		long long all = d*(d-1)/2;
		ans += (n-all)*d;
		printf("%lld\n", ans);
	}
	return 0;
}

/**
 * 1+2+3+...+d-1+d >= n >= 1+2+3+...+d-1
 * d*(d+1)/2 >= n > d*(d-1)/2
**/