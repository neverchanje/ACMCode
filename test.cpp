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

stack<int> seq;

int main()
{
	freopen("a.txt", "r", stdin);

    while(cin>>n>>k){

		bool need_optimalize = false;

        memset(cluster, 0, sizeof(cluster));

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

        while (!seq.empty())
            seq.pop();

        for(int ii=1; ii<=n; ii++)
        {
            if(!cluster[ii])
                continue;
            
            //j是目标位置
            int j = cluster[ii];
            //目标位置是空的，直接放进去
            if(!cluster[j])
            {
                if(!need_optimalize)
                    need_optimalize = true;
                cluster[ii] = 0;
                cluster[j] = j;
                printf("%d %d\n", ii, j);
                continue;
            }
            
            //当目标位置被占用时（cluster[j]>0），意味着遇到链或者循环
            if(ii != cluster[ii])
            {
                if(!need_optimalize) need_optimalize = true;
                
                seq.push(ii);
                int i = cluster[ii];
                cluster[ii] = ii;
                while(ii != i && i != 0)
                {
                    seq.push(i);
                    int k = cluster[i];
                    cluster[i] = i;
                    i = k;

                    if(ii == i)
                    {
                        printf("%d %d\n", seq.top(), n);
                    }
                }
                
                while(seq.size() > 1)
                {
                    int k = seq.top();
                    seq.pop();
                    printf("%d %d\n", seq.top(), k);
                }
                
                if(ii == i)	printf("%d %d\n", n, seq.top());
                else cluster[seq.top()] = 0; //是链的话要记得留一个空位
                if(!seq.empty()) seq.pop();
                continue;
            }
        }

        if(!need_optimalize)
            puts("No optimization needed");
    }
    return 0;
}
