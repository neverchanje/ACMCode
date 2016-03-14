
// trie
const int maxnode = 1000002;
int ch[maxnode][26] = {0};
int val[maxnode] = {0};
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

