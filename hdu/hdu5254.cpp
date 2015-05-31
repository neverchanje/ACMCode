#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 510;

int T, n, m, g;
bool field[maxn][maxn];

void solve(int i, int j) {
    if (i>0 && j>0 && field[i-1][j-1]) {
        if (!field[i-1][j]) {
            field[i-1][j] = true;
            solve(i-1, j);
        }
        if (!field[i][j-1]) {
            field[i][j-1] = true;
            solve(i, j-1);
        }
    }

    if (i<n-1 && j<m-1 && field[i+1][j+1]) {
        if (!field[i+1][j]) {
            field[i+1][j] = true;
            solve(i+1, j);
        }
        if (!field[i][j+1]) {
            field[i][j+1] = true;
            solve(i, j+1);
        }
    }

    if (i>0 && j<m-1 && field[i-1][j+1]) {
        if (!field[i-1][j]) {
            field[i-1][j] = true;
            solve(i-1, j);
        }
        if (!field[i][j+1]) {
            field[i][j+1] = true;
            solve(i, j+1);
        }
    }
    
    if (i<n-1 && j<m-1 && field[i+1][j-1]) {
        if (!field[i][j-1]) {
            field[i][j-1] = true;
            solve(i, j-1);
        }
        if (!field[i+1][j]) {
            field[i+1][j] = true;
            solve(i+1, j);
        }
    }
       
}

int main() {
		
//	freopen("a.in", "r", stdin);
//	freopen("b.out", "w", stdout);
	
    cin>>T;

    int x, y;

	for (int kase = 1; kase <= T; ++kase)
	{
        printf("Case #%d:\n", kase);	
        cin>>n>>m;

        memset(field, 0, sizeof(field));

        cin>>g;
        int x, y;
        for (int i = 0; i < g; ++i) {
        	cin>>x>>y;
        	field[x-1][y-1] = true;
        }

        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < m; ++j) {
                if (!field[i][j])
                    continue;
                solve(i, j);
        	}
        }

        int occupied = 0;
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < m; ++j) {
        		if (field[i][j]) {
        			occupied++;
        		}
        	}
        }
        cout<<occupied<<endl;
    }
	return 0;
}