#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, k;
const int maxn = 10005;

int cluster[maxn];

int si, c;

bool need_optimalize = false;

stack<int> seq;

int main()
{
    memset(cluster, 0, sizeof(cluster));
    
    cin>>n>>k;
    
    int cnt = 0;
    for(int i=0; i<k; i++)
    {
        cin>>si;
        for(int j=0; j<si; j++)
        {
            cin>>c;
            cluster[c] = ++cnt;
        }
    }
   
    for(int i=1; i<=n; i++)
    {
        if(cluster[i]==i || !cluster[i])
            continue;
        
        need_optimalize = true;
        
        seq.push(i);
        int next = cluster[i];
        cluster[i] = i;
        
        bool isCircle = false;
        while (true) {
            if(cluster[next] == i){
                isCircle = true;
                break;
            }
            if(cluster[next] == 0)
                break;
            seq.push(next);
            next = cluster[next];
        }
        
        if (isCircle)
        {
            int j = n;
            while( cluster[j] )
                j--;
            
            printf("%d %d\n", next, j);
            while(!seq.empty())
            {
                int t = seq.top();
                seq.pop();
                printf("%d %d\n", t, next);
                cluster[next]=next;
                next = t;
            }
            printf("%d %d\n", j, next);
            cluster[next] = next;
        }
        else
        {
            cluster[next] = 0;
            while(!seq.empty())
            {
                int t = seq.top();
                seq.pop();
                printf("%d %d\n", t, next);
                cluster[next]=next;
                next = t;
            }
            cluster[next] = 0;
        }
    }
    
    if(!need_optimalize)
        puts("No optimization needed");

    return 0;
}
