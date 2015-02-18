#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int n;
int way[maxn];

int step; // upper bound
int ans;

//已经求得 way[1], ... way[cur], 要猜出 way[cur+1] 的值
bool dfs(int cur)
{
    if( cur > step )
        return false;
    if( way[cur] == n )
        return true;
    if( way[cur] <= 0 || way[cur]>10000)
        return false;
    if( way[cur]*(1<<(step-cur)) < n) // 强剪枝
        return false;
    
    for(int i=0; i<=cur; i++)
    {
        way[cur+1] = way[cur] + way[i];
        if(dfs(cur+1))
            return true;
        way[cur+1] = way[cur] - way[i];
        if(dfs(cur+1))
            return true;
    }
    return false;
}

int main()
{
    while(cin>>n && n)
    {
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        
        step=1;
        while(true)
        {
            way[0] = 1;
            if(dfs(0))
                break;
            step++;
        }
        cout<<step<<endl;
    }
    return 0;
}
