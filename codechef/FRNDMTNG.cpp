#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxn = 2002;
const long long INF = 1e9+7;
const long long MOD = 1e9;

long long dp[maxn][maxn], f[maxn];

int main() {
    
    int T, N, M;
    long long sum;
    
    //freopen("a.in", "r", stdin);
    
    cin>>T;

    for (int kase=1; kase<=T; kase++) {
    
        cin>>N>>M;
        
        for (int i=0; i<=M; i++) f[i] = 1;
        for (int i=2; i<=M; i++) {
            f[0] = 1;
            for (int j=1; j<=M; j++) {
                f[j] = (f[j] + f[j-1]) % MOD;
            } 
        }
        
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<=M; i++) {
            dp[1][i] = f[i];
        }
        for (int i=2; i<=N; i++) {
            sum = 0;
            for (int j=0; j<=M; j++) {
                sum = (dp[i-1][j] + sum) % MOD;
                dp[i][j] = (sum * f[j]) % MOD;
            }
        }
        
        long long ans = 0;
        for (int i=0; i<=M; i++) {
            ans = (dp[N][i] + ans) % MOD;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
 