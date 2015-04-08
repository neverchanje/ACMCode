#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

int T;
ll r, t, k;

bool C(ll v)
{
    return 2*v*v+(2*r-1)*v <= t;
}

int main() {
    
    freopen("a.in", "r", stdin);
    freopen("b.out", "w", stdout);
    
    cin>>T;
    int kase = 1;
    while (cin>>r>>t) 
    {
        printf("Case #%d: ", kase++);

        ll lb=0, rb=min(t/(2*r-1), (ll)sqrt(t/2)), mid;
        while(lb<=rb)
        {
            mid = (rb+lb)/2;
            if (C(mid))
                lb=mid+1;
            else 
                rb=mid-1;
        }
        cout<<rb<<endl;
    }
}
