/*
 * 621E.cc
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <bitset>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 400002;

int c[maxn], n, m;

vector<int> to[maxn];
int idmap[maxn];
int soncnt[maxn];

int globid;

// in dfs order
// new root is 1
void reorder(int root, int pa) {
    idmap[root] = ++globid;
    for (int i = 0; i < to[root].size(); i++) {
        int child = to[root][i];
        if (child == pa) continue;
        reorder(child, root);
        soncnt[root] += soncnt[child] + 1;  // +1 for child
    }
}

struct treenode {
    int l, r;
    bool lazy;
    // data to be maintained by segment tree
    uint64_t color;
};
treenode segtree[maxn * 4];

#define LCHILD(o) (2 * o)
#define RCHILD(o) (2 * o + 1)

void segtree_init(int o, int l, int r) {
    assert(l <= r);
    segtree[o].l = l;
    segtree[o].r = r;
    segtree[o].lazy = false;
    segtree[o].color = 0;

    if (l == r) return;

    int mid = (l + r) / 2;
    segtree_init(LCHILD(o), l, mid);
    segtree_init(RCHILD(o), mid + 1, r);
}

void segtree_init() { segtree_init(1, 1, n); }

void push_down(int o) {
    if (segtree[o].lazy) {
        segtree[LCHILD(o)].color = segtree[RCHILD(o)].color = segtree[o].color;
        segtree[o].lazy = false;
        segtree[LCHILD(o)].lazy = true;
        segtree[RCHILD(o)].lazy = true;
    }
}

void push_up(int o) {
    if (segtree[o].l < segtree[o].r) {
        segtree[o].color =
            (segtree[LCHILD(o)].color | segtree[RCHILD(o)].color);
    }
}

// @param o is the id of the current tree node.
void segtree_update(int o, int l, int r, int newcolor) {
    assert(l <= r);
    // printf("o: %d, segtree[o].l: %d, segtree[o].r : %d, l: %d, r: %d\n", o,
    // segtree[o].l, segtree[o].r, l, r);
    if (l <= segtree[o].l && r >= segtree[o].r) {
        segtree[o].color = uint64_t(1LL << newcolor);
        segtree[o].lazy = true;
        return;
    }

    push_down(o);
    int seg_mid = (segtree[o].l + segtree[o].r) / 2;
    if (l <= seg_mid) segtree_update(LCHILD(o), l, r, newcolor);
    if (r >= seg_mid + 1) segtree_update(RCHILD(o), l, r, newcolor);
    push_up(o);
}

int bitcount(uint64_t val) {
    int cnt = 0;
    for (int i = 0; i <= 60; i++) {
        if ((val >> i) & 1) cnt++;
    }
    return cnt;
}

void segtree_query(int o, int l, int r, uint64_t &ans) {
    assert(l <= r);
    if (l <= segtree[o].l && r >= segtree[o].r) {
        ans |= segtree[o].color;
        return;
    }

    push_down(o);
    int seg_mid = (segtree[o].l + segtree[o].r) / 2;
    if (l <= seg_mid) segtree_query(LCHILD(o), l, r, ans);
    if (r >= seg_mid + 1) segtree_query(RCHILD(o), l, r, ans);
    push_up(o);
}

void dump_segtree(int o) {
    printf("o: %d, l: %d, r: %d\n", o, segtree[o].l, segtree[o].r);
    if (segtree[o].l == segtree[o].r) {
        return;
    }
    dump_segtree(LCHILD(o));
    dump_segtree(RCHILD(o));
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

    // construct tree
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        to[x].push_back(y);
        to[y].push_back(x);
    }

    // do reorder
    globid = 0;
    memset(soncnt, 0, sizeof(soncnt));
    reorder(1, -1);

    // segment tree initialization
    segtree_init();

    //
    for (int i = 1; i <= n; i++) segtree_update(1, idmap[i], idmap[i], c[i]);

    //
    int tk, vk, ck;
    for (int i = 0; i < m; i++) {
        scanf("%d", &tk);
        if (tk == 1) {
            scanf(" %d %d", &vk, &ck);
            /// printf("from %d, to %d\n", idmap[vk], idmap[vk] + soncnt[vk]);
            segtree_update(1, idmap[vk], idmap[vk] + soncnt[vk], ck);
        } else {
            scanf(" %d", &vk);
            uint64_t ans = 0;
            // printf("from %d, to %d\n", idmap[vk], idmap[vk] + soncnt[vk]);
            segtree_query(1, idmap[vk], idmap[vk] + soncnt[vk], ans);
            printf("%d\n", bitcount(ans));
        }
    }

    return 0;
}
