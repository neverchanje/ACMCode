#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxn = 1000000+5;

int T;

ll gcd(ll a, ll b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

bool isPowOfTwo(ll y)
{
    int d=0;
    bool powOfTwo = true;
    while(y)
    {
        if (y!=1 && (y&1)){
            powOfTwo = false;
            break;
        }
        y/=2;
    }
    return powOfTwo;
}

int digit(ll y)
{
    int cnt=0;
    while(y)
    {
        y/=2;
        cnt++;
    }
    return cnt;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("b.out", "w", stdout);

	cin>>T;
	for (int kase = 1; kase <= T; ++kase)
	{
        ll x, y, g, d;
        scanf("%lld/%lld", &x, &y);
        printf("Case #%d: ", kase);

        g = gcd(x, y);
        x/=g; y/=g;
        d = digit(y)-1;

        if (!isPowOfTwo(y) || d>=40)
        {
            puts("impossible");
            continue;
        }
 
        ll p=x, q=y;
        int ans=0;
        while(q)
        {
            ans++;
            if (2*p >= q)
                break;
            p = max(p-1, (ll)1);
            q /= 2;
            g = gcd(p, q);
            p/=g; q/=g;
        }

        printf("%d\n", ans);
    }
}

/**
 * P/Q 是由  x/(Q/2) + y/(Q/2) (x+y=P)结合而来的
 * x = 1, y = P-1
 * 将问题转换为 (P-1)/(Q/2)
 * 判断 P/Q 能否有 1/1 的父亲
 * 即判断 2P - Q >= 0，P >= Q/2
 */