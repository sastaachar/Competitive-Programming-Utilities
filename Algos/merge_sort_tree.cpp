#include <bits/stdc++.h>

using namespace std;

const int max_n = 30001;

// tree should be nlogn size

vector<int> tree[450000];
int data[max_n];

void fillTree(int v, int l, int r) {
    if (l == r) {
        tree[v].push_back(data[l]);
        return;
    }

    int mid = (l + r) / 2;
    fillTree(2 * v, l, mid);
    fillTree(2 * v + 1, mid + 1, r);

    int i = 0, j = 0;

    while (i < tree[2 * v].size() && j < tree[2 * v + 1].size()) {
        if (tree[2 * v][i] < tree[2 * v + 1][j])
            tree[v].push_back(tree[2 * v][i++]);
        else
            tree[v].push_back(tree[2 * v + 1][j++]);
    }

    while (i < tree[2 * v].size()) {
        tree[v].push_back(tree[2 * v][i++]);
    }
    while (j < tree[2 * v + 1].size()) {
        tree[v].push_back(tree[2 * v + 1][j++]);
    }
}

const int DEF = 0;

// computation
int comp(int a, int b) {
    return a + b;
}

int query(int fl, int fr, int k, int v, int l, int r) {
    //   fl  fr l r
    //   l    r
    // ...........

    if (l > fr || r < fl) {
        return DEF;
    }

    if (l >= fl && r <= fr) {
        int lower = lower_bound(tree[v].begin(), tree[v].end(), k) - tree[v].begin();

        int ans = tree[v].size() - lower;
        if (ans < 0) ans = 0;

        return ans;
    }

    const int mid = (l + r) / 2;
    const int left = query(fl, fr, k, 2 * v, l, mid);
    const int right = query(fl, fr, k, 2 * v + 1, mid + 1, r);
    return left + right;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> data[i];
    fillTree(1, 0, n - 1);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(l - 1, r - 1, k + 1, 1, 0, n - 1) << "\n";
    }
}