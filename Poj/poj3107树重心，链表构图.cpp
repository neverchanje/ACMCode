#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

const int maxn = 500000;
const int INF = 999999999;
int n;

int head[maxn];
struct edgednode{
    int u, v, next;
}edge[maxn];

int edgenum = 0;
void addedge(int u, int v)
{
    edge[edgenum].u = u;
    edge[edgenum].v = v;
    edge[edgenum].next = head[u];
    head[u] = edgenum++;
}

int son[maxn];
int maxson[maxn];
int minmaxson = INF;

void dfs(int u, int fa)
{
    int v;
    for(int i=head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if( v==fa ) continue;
        dfs(v, u);
        son[u] += son[v];
        maxson[u] = max(maxson[u], son[v]);
    }
    
    son[u] += 1; //包括自己
    maxson[u] = max(maxson[u], n-son[u]);
    
    minmaxson = min(maxson[u], minmaxson);
}

int main()
{
    while(cin>>n){
    
        memset(head, -1, sizeof(head));
        memset(son, 0, sizeof(son));
        memset(maxson, 0, sizeof(maxson));
        
        int u, v;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        
        dfs(1, -1);

        vector<int> ans;
        for(int i=1; i<=n; i++)
        {
            if(minmaxson == maxson[i])
                ans.push_back(i);
        }
        
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++){
            if(i) putchar(' ');
            printf("%d", ans[i]);
        }
    }
}
