#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = 1010;

int t, n;

int maxson[maxn];

vector<int> edge[maxn];

void init ()
{
    for(int i=0; i<=n; i++) edge[i].clear();
}

void addedge(int u, int v)
{
    edge[u].push_back(v);
    edge[v].push_back(u);
}

void dfs(int u, int pa)
{
    int v;
    
    for (int i=0; i<edge[u].size(); i++) {
        v = edge[u][i];
        if (v == pa) continue;
        dfs(v, u);
    }
    
    maxson[u] = 1;

    int id1=-1, id2=-1, maxv = 0;
    for (int i=0; i<edge[u].size(); i++) {
        v = edge[u][i];
        if (v == pa) continue;
        if (maxson[v] > maxv){
            maxv = maxson[v];
            id1 = v;
        }
    }

    maxv = 0;
    for (int i=0; i<edge[u].size(); i++) {
        v = edge[u][i];
        if (v == pa) continue;
        if (v!=id1 && maxson[v] > maxv) {
            maxv = maxson[v];
            id2 = v;
        }
    }

    if (id1>=0 && id2>=0)
        maxson[u] += ( maxson[id1] + maxson[id2] );
    else
        maxson[u] = 1;
}

int main() {

    freopen("B-small-practice.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int kase = 1;
    cin>>t;
    
    while (cin>>n) {
        
        init();
        
        int x, y;
        for (int i=0; i<n-1; i++){
            scanf("%d %d", &x, &y);
            addedge(x, y);
        }
        
        printf("Case #%d: ", kase++);
        
        int ans = 0xFFFFFFF;
        for (int i=1; i<=n; i++) {
            dfs(i, -1);
            ans = min(ans, n-maxson[i]);
        }
        cout<<ans<<endl;
    }
}

  

/*
 显然有：
 题意：最少删掉多少节点才能让一棵树变成完全二叉树
 这里对完全二叉树的定义和我以为的不太一样。。只要所有的节点的都只有0或2个儿子，这就是完全二叉树
 
 在p的子树中保留两棵子树，这两棵子树所需要删除的节点数最少
 
 del[p] = del[lc] + del[rc] + cnt[otherc]
        = del[lc] + del[rc] + sum(cnt[c]) - cnt[lc] - cnt[rc]
 
 找到 lc, rc 的操作是 O(n) 的 dp[lc] = min(dp), dp[rc] = min2(dp)
 如果只有 lc，则 del[p] = cnt[lc]
 如果两个都没有，则 del[p] = 0
*/