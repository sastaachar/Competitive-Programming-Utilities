#include <bits/stdc++.h>
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(a, siz, i) for (int i = a; i < siz; i++)
#define fe(siz) for (int sasta = 0; sasta < siz; sasta++)
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define ss second
#define ff first
// clang-format off
#define vin(arr,n) fe(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) fe(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

// ! q - https://www.spoj.com/submit/KQUERY/
// binarysearch mergesort segmenttree

vi merge_nodes(vi &left_node, vi &right_node) {
    int n = left_node.size(), m = right_node.size();
    vi final_node;

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (left_node[i] < right_node[j])
            final_node.pb(left_node[i++]);
        else
            final_node.pb(right_node[j++]);
    }

    if (i != n)
        while (i != n) final_node.pb(left_node[i++]);
    if (j != m)
        while (j != m) final_node.pb(right_node[j++]);

    return final_node;
}

void make_tree(vi &arr, vvi &tree, int cur_i, int cur_l, int cur_r) {
    if (cur_l == cur_r) {
        tree[cur_i] = vi(1, arr[cur_l - 1]);
        return;
    }

    int mid = (cur_l + cur_r) / 2;

    make_tree(arr, tree, 2 * cur_i, cur_l, mid);
    make_tree(arr, tree, 2 * cur_i + 1, mid + 1, cur_r);

    tree[cur_i] = merge_nodes(tree[2 * cur_i], tree[2 * cur_i + 1]);
}

int bin_srch(vi &arr, int k) {
    int l = 0, r = arr.size() - 1;

    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] == k) return mid;

        if (arr[mid] > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (arr[l] < k) ++l;
    return l;
}

int count_greater(vi &arr, int k) {
    int pos = bin_srch(arr, k + 1);

    if (pos != -1) {
        return arr.size() - pos;
    }
    return 0;
}

int query(int l, int r, int k, vvi &tree, int cur_i, int cur_l, int cur_r) {
    int total_count = 0;
    if (l <= cur_l && r >= cur_r) {
        total_count += count_greater(tree[cur_i], k);
    } else if ((l >= cur_l && l <= cur_r) || (r >= cur_l && r <= cur_r)) {
        int mid = (cur_l + cur_r) / 2;

        total_count += query(l, r, k, tree, 2 * cur_i, cur_l, mid);
        total_count += query(l, r, k, tree, 2 * cur_i + 1, mid + 1, cur_r);
    }
    return total_count;
}

void solve() {
    int n;
    cin >> n;
    vi arr;
    vin(arr, n);
    int q;
    cin >> q;

    vvi tree(4 * n);
    make_tree(arr, tree, 1, 1, n);

    fr(q, _i) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i, j, k, tree, 1, 1, n) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}