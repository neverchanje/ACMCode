#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T, N;

struct node{
	node *ch[26];
	bool black;

	node(){
		for(int i=0; i<26; i++)
			ch[i] = NULL;
		black = false;
	}
};

struct Trie{
	node* root;

	int getId(char x){
		return x - 'a';
	}

	int insert(char str[]){
		int len = strlen(str);
		node* p = root;
		int i=1;
		int ans = 0;
	
		while(i<=len){
			int id = getId(str[i-1]);
		
			if(p->ch[id] == NULL)
				p->ch[id] = new node();
			p = p->ch[id];
			//如果第一次发现了不是黑色的节点，则该节点就可以作为AutoComplete
			if(!p->black && !ans){
				ans = i;
			}
			p->black = true;
			i++;
		}
		if(ans == 0)
			ans = len;
		return ans;
	}
}trie;

const int maxn = 1e6+10;
char str[maxn];

int main(){
//	freopen("a.txt", "r", stdin);
//	freopen("b.txt", "w", stdout);
	cin>>T;
	for(int kase=1; kase<=T; kase++)
	{
		printf("Case #%d: ", kase);
		trie.root = new node();
		cin>>N;
		getchar();

		int ans = 0;
		for(int i=0; i<N; i++)
		{
			str[0] = '\0';
			gets(str);
			ans += trie.insert(str);
		}
		cout<<ans<<endl;
	}
	return 0;
}
