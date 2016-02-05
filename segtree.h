/*
 * segtree.h
 * Copyright (C) 2016 neverchanje <neverchanje@neverchanjes-mac.local>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef SEGTREE_H
#define SEGTREE_H

const int maxn = 10000;

struct treenode {
    int l, r;
    // data maintained by segment tree
    // is placed here
};
treenode segtree[maxn * 4];

#define LCHILD(o) (2 * o)
#define RCHILD(o) (2 * o + 1)

void segtree_init(int o, int l, int r) {
    assert(l <= r);
    segtree[o].l = l;
    segtree[o].r = r;
    segtree[o].lazy = false;
    // initialize internal data in segtree[o]

    if (l == r) return;

    int mid = (l + r) / 2;
    segtree_init(LCHILD(o), l, mid);
    segtree_init(RCHILD(o), mid + 1, r);
}

void segtree_init() { segtree_init(1, 1, n); }

void push_down(int o) {
    if (segtree[o].lazy) {
        // push down internal data to left and right child
        segtree[o].lazy = false;
        segtree[LCHILD(o)].lazy = true;
        segtree[RCHILD(o)].lazy = true;
    }
}

void push_up(int o) {
    if (segtree[o].l < segtree[o].r) {
        // push up internal data from left and right child
    }
}

// @param o is the id of the current tree node.
void segtree_update(int o, int l, int r, int newcolor) {
    assert(l <= r);
    if (l <= segtree[o].l && r >= segtree[o].r) {
        // update internal data
        segtree[o].lazy = true;
        return;
    }

    push_down(o);
    int seg_mid = (segtree[o].l + segtree[o].r) / 2;
    if (l <= seg_mid) segtree_update(LCHILD(o), l, r, newcolor);
    if (r >= seg_mid + 1) segtree_update(RCHILD(o), l, r, newcolor);
    push_up(o);
}

void segtree_update(int l, int r, int newcolor) {
    segtree_update(1, l, r, newcolor);
}

void segtree_query(int o, int l, int r, uint64_t &ans) {
    assert(l <= r);
    if (l <= segtree[o].l && r >= segtree[o].r) {
        // update ans
        return;
    }
    push_down(o);
    int seg_mid = (segtree[o].l + segtree[o].r) / 2;
    if (l <= seg_mid) segtree_query(LCHILD(o), l, r, ans);
    if (r >= seg_mid + 1) segtree_query(RCHILD(o), l, r, ans);
    push_up(o);
}

void segtree_query(int l, int r, uint64_t &ans) { segtree_query(1, l, r, ans); }

void dump_segtree(int o) {
    printf("o: %d, l: %d, r: %d\n", o, segtree[o].l, segtree[o].r);
    if (segtree[o].l == segtree[o].r) {
        return;
    }
    dump_segtree(LCHILD(o));
    dump_segtree(RCHILD(o));
}

#endif /* !SEGTREE_H */
