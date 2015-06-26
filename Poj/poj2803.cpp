#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxn = 100001;
const long long INF = 1e9+7;
const long long MOD = 1e9;

char word[101];
char prefix[][6] = {"anti", "post", "pre", "re", "un"};
char postfix[][6] = {"er", "ing", "ize", "s", "tion"};
char ans[200];

int main() {
    
   // freopen("a.in", "r", stdin);
    
    int n;
    
    scanf("%d", &n);
    
    while(n--) {
        
        scanf("%s", word);
        
        memset(ans, 0, sizeof(ans));
        
        //每个词只会有一个前缀，一个后缀
        int plen, len, pre_id=-1, post_id=-1;
        
        len = strlen(word);
        
        for(int i=0; i<5; i++) {
            
            plen = strlen(prefix[i]);
            
            if(plen > len) continue;
            
            if(strncmp(word, prefix[i], plen) != 0)
                continue;
            
            if( i==0 ) {
                strcat(ans, "against ");
            } else if( i==1 ) {
                strcat(ans, "after ");
            } else if( i==2 ) {
                strcat(ans, "before ");
            } else if( i==4 ) {
                strcat(ans, "not ");
            }
            
            pre_id = i;    
            
            strcpy(word, word+plen); //前缀没用了，去掉它
            
            break;
        }
        
        len = strlen(word);
        
        for(int i=0; i<5; i++) {
            
            plen = strlen(postfix[i]);
            
            if(plen > len) continue;
            
            if(strncmp(word+len-plen, postfix[i], plen) != 0)
                continue;
        
            if( i==0 ) {
                strcat(ans, "one who ");
            } else if( i==1 ) {
                strcat(ans, "to actively ");
            } else if( i==2 ) {
                strcat(ans, "change into ");
            } else if( i==3 ) {
                strcat(ans, "multiple instances of ");
            } else if( i==4 ) {
                strcat(ans, "the process of ");
            }
            
            post_id = i;
            
            break;
        }
        
        ///先处理前面的，再处理后面的
        
        if(post_id != -1) {
            plen = strlen(postfix[post_id]);
            strncat(ans, word, len - plen); //去掉后缀
        } else {
            strcat(ans, word);
        }
        
        if(post_id == 0) {
            strcat(ans, "s");
        } else if( post_id == 4) {
            strcat(ans, "ing");
        }
        
        if(pre_id == 3) {
            strcat(ans, " again");
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
 