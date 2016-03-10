
// trie
const int M = 1000002;
int ch[M][26] = {0};
int val[M] = {0};
int ndtot = 1, rt = 0;
void insert(char *s, int v) {
    int u = rt;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (!ch[u][c]) {
            ch[u][c] = ndtot++;
        }
        u = ch[u][c];
    }
}

