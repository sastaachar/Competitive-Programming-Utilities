#include <bits/stdc++.h>

using namespace std;

/*
    * size of a segmenttree can be taken as 4n
    //// https://www.quora.com/Why-does-4-*-N-space-have-to-be-allocated-for-a-segment-tree-where-N-is-the-size-of-the-original-array
    
    * my explanation not sure if its right
    * size of binary tree = 2^(h+1) - 1
    * h = ceil( log2(n) )
    * we can remove ceil by adding +1 for worst case
    ! h = log2(n) + 1
    ! 2^(log2(n)) = n
    * size <= 2^(log2(n) + 1+1) - 1      (put h = log2(n) + 1)
    * size <= 2^(log2(n) + 2) - 1
    * size <= (2^2 * 2^(log2(n) ) ) - 1  (put 2^(log2(n)) = n)
    * size <= (4 * n) - 1
    * size < 4n
    * so 4*n should be enough
*/

int comp(int a, int b) {
    return a + b;
}
int DEF = 0;

void fillTree(int v, int l, int r, vector<int> &data, vector<int> &tree) {
    for (int i = 0; i < tree.size(); i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
    if (l == r) {
        tree[v] = data[l];
    } else {
        int mid = (l + r) / 2;
        fillTree(2 * v, l, mid, data, tree);
        fillTree(2 * v + 1, mid + 1, r, data, tree);
        tree[v] = comp(tree[2 * v], tree[2 * v + 1]);
    }
}

vector<int> makeTree(vector<int> data) {
    int n = data.size();
    vector<int> tree(4 * n);
    fillTree(1, 0, n - 1, data, tree);
    return tree;
}

int query(int fl, int fr, int v, int l, int r, vector<int> tree) {
    if (fl <= l && fr >= r) {
        return tree[v];
    }

    if (fl > r || fr < l) return DEF;

    int mid = (l + r) / 2;
    return comp(query(fl, fr, 2 * v, l, mid, tree), query(fl, fr, 2 * v + 1, mid + 1, r, tree));
}

int main() {
    vector<int> data{1, 3, 4, 5, 6, 7};

    vector<int> tree = makeTree(data);

    for (int i = 0; i < tree.size(); i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
    int n = data.size();
    cout << query(1, 2, 1, 0, n - 1, tree) << "\n";  // 3 4         -> 07
    cout << query(3, 5, 1, 0, n - 1, tree) << "\n";  // 5 6 7       -> 18
    cout << query(0, 5, 1, 0, n - 1, tree) << "\n";  // 1 3 4 5 6 7 -> 26
    cout << query(2, 5, 1, 0, n - 1, tree) << "\n";  // 4 5 6 7     -> 22
}