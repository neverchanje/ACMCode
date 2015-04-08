#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

int t, n, l;

const int maxn = 155;

int ans;

ll s[maxn], e[maxn], tmp[maxn];

int countbit(ll v)
{
    int ret = 0;
    while (v)
    {  
        ret += (v&1);
        v>>=1;
    }
    return ret;
}

bool solve()
{
    int sv, ev;
    bool same;

    ans = 1000;

    ll dif; int difcnt;

    //s[0] 对应 e[j]
    for (int j=0; j<n; j++)
    {    
        //记录不一样的位置
        dif = s[0] ^ e[j];
        difcnt = countbit(dif);

        for (int i = 0; i < n; ++i)
            tmp[i] = (s[i] ^ dif);

        sort(tmp, tmp+n);

        same = true;
        for (int i=0; i<n; i++) {
            if (tmp[i] != e[i]){
                same = false;
                break;
            }
        }
        if (same) ans = min(ans, difcnt);
    }

    return ans != 1000;
}

int main() {

    freopen("A-small-practice.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int kase = 1;
    cin>>t;
    while(cin>>n>>l){

        getchar();
        char d;

        ll v;
        for(int i=0; i<n; i++){
            v = 0;
            for (int j=0; j<l; j++){
                scanf("%c", &d);
                v <<= 1;
                v |= d-'0';
            }
            s[i] = v;
            getchar();
        }

        for(int i=0; i<n; i++){
            v = 0;
            for (int j=0; j<l; j++){
                scanf("%c", &d);
                v <<= 1;
                v |= d-'0';
            }
            e[i] = v;
            getchar();
        }

        printf("Case #%d: ", kase++);

        sort(e, e+n);

        if (solve())
            printf("%d\n", ans);
        else
            puts("NOT POSSIBLE");
    }
}