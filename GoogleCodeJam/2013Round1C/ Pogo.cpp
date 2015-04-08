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

int main() {
	freopen("a.in", "r", stdin);
	freopen("b.out", "w", stdout);

	cin>>T;
	for (int kase = 1; kase <= T; ++kase)
	{
        int tx, ty;
        cin>>tx>>ty;

        int dx, dy;
        int maxstep = 3*sqrt(2*(abs(tx)+abs(ty)));
        string path;

        int i;
        for (i = 1; i <= maxstep; ++i)
        {
            int k = i;
            path = "";
            dx = tx, dy = ty;
            while(k)
            {
                if (abs(dx) > abs(dy)){
                    if (dx > 0){
                        dx -= k;
                        path += 'E';
                    }
                    else
                    {
                        dx += k;
                        path += 'W';
                    }
                }
                else{
                    if (dy > 0){
                        dy -= k;
                        path += 'N';
                    }
                    else
                    {
                        dy += k;
                        path += 'S';
                    }   
                }
                k--;
            }
            if (dx==0 && dy==0)
                break;
        }
        printf("Case #%d: ", kase);
        for (int ii = i-1; ii >= 0; ii--)
            cout<<path[ii];
        puts("");
    }
}

/**
 * 显然步数的上界是 2(|dx| + |dy|) //来回折返，每次往目标方向前进1步
 * 步数的上界可以减少到 sqrt(2(|dx|+|dy|))
 * 枚举最后一步的大小 : i
 * 假设最后一步在y轴
 * 将原本的 (dx, dy) 问题转化为 (dx, dy+i) 或 (dx, dy-i)
 * 贪心的将问题转到 (dx, dy-i)
 * 同理也可以转到 (dx-i, dy)
 * 选择 |dx| 和 |dy| 中最大的那个
 */ 