#define mset(arr, val) memset((arr), val, sizeof(arr))
#define rep(i, a, n) for (int i = a; i < n; i++)

// trie
struct Trie {
    static const int M = 1000002;
    int ch[M][26];
    int val[M];
    int sz;
    Trie() {
        sz = 0;
        mset(ch, 0);
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        rep(i, 0, n) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
} tree;