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
string s;
int n, a[maxn];

struct Interval
{
	int l, r;
	Interval(){}
	Interval(int l, int r):l(l), r(r){}
};
vector<Interval> intv;

int main() {
	freopen("a.in", "r", stdin);
	freopen("b.out", "w", stdout);

	cin>>T;
	for (int kase = 1; kase <= T; ++kase)
	{
		cin>>s>>n;
        
		intv.clear();

        int len=s.length();
		for (int i = 0; i < len; ++i)
		{
			char c = s[i];
			if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
				a[i] = 0;
			else a[i] = 1;
		}

		ll li=0, ri=0;
		
		while (li < len)
		{
			if (a[li])
			{
				ri = li+1;
				while(ri < len && a[ri]) ri++;
				if (ri-li >= n)
					intv.push_back(Interval(li, ri-1));	
                li = ri;
            }
            else li++;
		}

		ll ans=0;
		for (int i = 0; i < intv.size(); ++i)
		{
            if (i==0)
                li = 0;
            else
                li = intv[i-1].r-n+2;
            ans += (intv[i].l - li) * (len-(intv[i].l+n-1));

           	li = intv[i].l+n-1;
           	ri = intv[i].r;
           	ans += (ri-li+1)*len - (li+ri)*(ri-li+1)/2;
  		}

		printf("Case #%d: ", kase);
		cout<<ans<<endl;
	}
}

/**
 * 写的太麻烦了
 */