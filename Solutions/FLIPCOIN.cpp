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

const ll SIZE = 4 * 100000 + 5;
int N;

ll tree[SIZE], lzy_tree[SIZE];

void update(int l, int r, int v, int _l, int _r) {
    int mid = l + (r - l) / 2;

    if (lzy_tree[v]) {
        tree[v] = (r - l + 1) - tree[v];
        if (l != r) {
            lzy_tree[2 * v] = !lzy_tree[2 * v];
            lzy_tree[2 * v + 1] = !lzy_tree[2 * v + 1];
        }
        lzy_tree[v] = 0;
    }

    if (r < _l || l > _r) return;

    if (l >= _l && r <= _r) {
        tree[v] = (r - l + 1) - tree[v];

        if (l != r) {
            lzy_tree[2 * v] = !lzy_tree[2 * v];
            lzy_tree[2 * v + 1] = !lzy_tree[2 * v + 1];
        }
        return;
    }

    update(l, mid, 2 * v, _l, _r);
    update(mid + 1, r, 2 * v + 1, _l, _r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int getCount(int l, int r, int v, int _l, int _r) {
    int mid = l + (r - l) / 2;

    if (lzy_tree[v]) {
        tree[v] = (r - l + 1) - tree[v];
        if (l != r) {
            lzy_tree[2 * v] = !lzy_tree[2 * v];
            lzy_tree[2 * v + 1] = !lzy_tree[2 * v + 1];
        }
        lzy_tree[v] = 0;
    }

    if (r < _l || l > _r) return 0;

    if (l >= _l && r <= _r) {
        return tree[v];
    }

    return getCount(l, mid, 2 * v, _l, _r) +
           getCount(mid + 1, r, 2 * v + 1, _l, _r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> N >> q;
    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c) {
            cout << getCount(0, N - 1, 1, l, r) << "\n";
        } else {
            update(0, N - 1, 1, l, r);
        }
    }
    return 0;
}