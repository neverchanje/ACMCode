#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX=10001;  

#define rep(i, x, y) for (int i=x; i<=y; i++)
#define mset(arr) memset(arr, 0, sizeof(arr))  


const int maxnode = 500010;
const int sigma_size = 26;

int T, N, M, P;

set<string> dict;

struct Tile {
	char C;
	int V; 
};

vector<Tile> vec;
char s[15];

int solve() {
	int ans = 0;

	for (int i = 0; i < (1<<P); ++i){
		string s;
		int value = 0;
		for (int j = 0; j < P; ++j) {
			if (i & (1<<j)) {
				s += vec[j].C;
				value += vec[j].V;
			}
		}

		sort(s.begin(), s.end());
		if (dict.find(s) != dict.end()) {
			ans = max(value, ans);
		}
	}

	return ans;
}

int main()  
{
	freopen("a.in", "r", stdin);

	cin>>N;
	string word;
	for (int i = 0; i < N; ++i) {
		cin>>word;
		sort(word.begin(), word.end()); //排序去重
		dict.insert(word);
	}
	
	cin>>M;
	char C;
	int V;
	while(M--) {
		cin>>P;

		vec.clear();

		int tmp = P;
		scanf("\n");
		while (tmp--) {
			Tile tile;
			scanf("%c %d\n", &tile.C, &tile.V);
			vec.push_back(tile);
		}
		cout<<solve()<<endl;
	}

    return 0;  
}	