#include <bits/stdc++.h>

using namespace std;

#define SEG_OPERATOR *

int tree[400000];
int initial[100000];

void build(int l, int r, int i) {
    if (l == r) {
        tree[i] = initial[l];

        return;
    }

    int mid = (l + r) / 2;

    int ll = i * 2 + 1;
    int rr = i * 2 + 2;

    build(l, mid, ll);
    build(mid + 1, r, rr);

    tree[i] = tree[ll] SEG_OPERATOR tree[rr];
}

void update(int l, int r, int i, int updi, int val) {
    if (l == r) {
        tree[i] = val;

        return;
    }

    int mid = (l + r) / 2;

    int ll = i * 2 + 1;
    int rr = i * 2 + 2;

    if (updi <= mid) {
        update(l, mid, ll, updi, val);
    } else {
        update(mid + 1, r, rr, updi, val);
    }

    tree[i] = tree[ll] SEG_OPERATOR tree[rr];
}

int query(int l, int r, int i, int ql, int qr) {
    if (l >= ql && r <= qr) {
        return tree[i];
    }

    if (r < ql || l > qr) {
        return 1;
    }

    int mid = (l + r) / 2;

    int ll = i * 2 + 1;
    int rr = i * 2 + 2;

    return query(l, mid, ll, ql, qr) SEG_OPERATOR query(mid + 1, r, rr, ql, qr);
}

int sign(int x) {
    if (x == 0) {
        return 0;
    }

    return x > 0 ? 1 : -1;
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &initial[i]);

            initial[i] = sign(initial[i]);
        }

        build(0, n - 1, 0);

        for (int i = 0; i < k; i++) {
            char opt;            
            scanf(" %c", &opt);

            if (opt == 'C') {
                int index, value;
                scanf("%d%d", &index, &value);

                update(0, n - 1, 0, index - 1, sign(value));
            } else {
                int l, r;
                scanf("%d%d", &l, &r);

                int value = query(0, n - 1, 0, l - 1, r - 1);

                if (value == 0) {
                    printf("0");
                } else if (value > 0) {
                    printf("+");
                } else {
                    printf("-");
                }
            }
        }

        printf("\n");
    }
}