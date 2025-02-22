#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, q, st[4 * N];

void update(int id, int l, int r, int p, int v) {
    if(p < l || p > r) 
        return;
    if(l == r && r == p) {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int x, int y) {
    if(y < l || x > r) 
        return 0;
    if(x <= l && r <= y) 
        return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, x, y), get(id * 2 + 1, mid + 1, r, x, y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int v, i;
            cin >> v >> i;
            update(1, 1, n, i, v);
        } else {
            int i, j;
            cin >> i >> j;
            cout << get(1, 1, n, i, j) << '\n';
        }
    }

    return 0;
}