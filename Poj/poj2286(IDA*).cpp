#include <iostream>
using namespace std;

const int dir[8][7] = {0, 2, 6, 11, 15, 20, 22,
                       1, 3, 8, 12, 17, 21, 23,
                       10, 9, 8, 7, 6, 5, 4,
                       19, 18, 17, 16, 15, 14, 13,
                       23, 21, 17, 12, 8, 3, 1,
                       22, 20, 15, 11, 6, 2, 0,
                       13, 14, 15, 16, 17, 18, 19,
                       4, 5, 6, 7, 8, 9, 10};

const int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

const int revert[8] = {5, 4, 7, 6, 1, 0, 3, 2};

int value[4];
int remain(int *block)
{
    memset(value, 0, sizeof(value));
    for(int i=0; i<8; i++)
        value[block[center[i]]]++;
    return 8 - max( max(value[1], value[2]), value[3] );
}

/*
        0     1
        2     3
 4  5   6  7  8  9 10
        11    12
 13 14  15 16 17 18 19
        20    21
        22    23
 */

int block[24];
char path[100];
int limit;

void push(int line, int *block)
{
    int tmp = block[dir[line][0]];
    for(int j=1; j<7; j++)
        block[dir[line][j-1]] = block[dir[line][j]];
    block[dir[line][6]] = tmp;
}

bool dfs(int cur)
{
    if(cur > limit)
        return false;
    int r = remain(block);
    if(r == 0)
        return true;
    if(limit-cur < r)
        return false;
    
    for (int i=0; i<8; i++) {
        push(i, block);
        path[cur+1] = 'A'+i;
        if(dfs(cur+1))
            return true;
        push(revert[i], block);
    }
    return false;
}

int main()
{
    while(cin>>block[0] && block[0])
    {
        for(int i=1; i<24; i++)
            cin>>block[i];
        
        if(remain(block) == 0)
        {
            puts("No moves needed");
            cout<<block[center[0]]<<endl;
            continue;
        }
        
        limit = 1;
        while(true)
        {
            if(dfs(0))
                break;
            limit++;
        }
        for(int i=1; i<=limit; i++)
            printf("%c", path[i]);
        cout<<endl<<block[center[0]]<<endl;
    }
    return 0;
}