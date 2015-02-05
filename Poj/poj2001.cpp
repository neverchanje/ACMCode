#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int n;

const int maxn = 1000 + 5;
string str[maxn];

struct TrieNode{
	int val;
	TrieNode* ch[26];

	TrieNode()
	{
		val = 1;
		for(int i=0; i<26; i++)
			ch[i] = NULL;
	}
};

struct Trie{
	TrieNode* root;

	Trie() {
		root = new TrieNode();
	}

	int getId(char x) {
		return x-'a';
	}

	void insert(string s)
	{
		TrieNode *p = root;
		int i=0;
		while(i < s.length()){
			int id = getId(s[i]);
			if(p->ch[id] == NULL)
			{
				p->ch[ id ] = new TrieNode();
			}
			else
			{
				( p->ch[ id ]->val )++;
			}
			p = p->ch[ id ];
			i++;
		}
	}

	int find(const string& s){
		TrieNode *p = root;
		int i=0; 
		while(i < s.length()){
			int id = getId(s[i]);
			p = p->ch[ id ];

			i++;
			if( p->val == 1)
				break;
		}
		return i;
	}
};

int main(){
//	freopen("a.txt", "r", stdin);

	Trie trie = Trie();
	int n=0;
	while(cin>>str[n]){
		trie.insert(str[n]);
		n++;
	}

	for(int i=0; i<n; i++)
	{
		int ans = trie.find(str[i]);
		cout<<str[i]<<" "<<str[i].substr(0, ans)<<endl;
	}

	return 0;
}