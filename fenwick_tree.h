
// fenwick tree / binary indexed tree
int C[maxn];

inline int lowbit(int x) { return x & (-x); }

inline int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

inline void add(int x, int d) {
    while (x <= n) {
        C[x] += d;
        x += lowbit(x);
    }
}
