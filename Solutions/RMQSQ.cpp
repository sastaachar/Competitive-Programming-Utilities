//! segment tree

#include <bits/stdc++.h>
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(siz, i, a) for (int i = a; i < siz; i++)
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
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

const int max_n = 100000;
int tree[4 * max_n];
int DEF = INT_MAX;
int n;
int data[max_n];

int comp(int a, int b) {
    return min(a, b);
}

void fillTree(int v, int l, int r) {
    if (l == r) {
        tree[v] = data[l];
    } else {
        int mid = (l + r) / 2;
        fillTree(2 * v, l, mid);
        fillTree(2 * v + 1, mid + 1, r);
        tree[v] = comp(tree[2 * v], tree[2 * v + 1]);
    }
}

int query(int fl, int fr, int v, int l, int r) {
    if (fl <= l && fr >= r) {
        return tree[v];
    }

    if (fl > r || fr < l) return DEF;

    int mid = (l + r) / 2;
    return comp(query(fl, fr, 2 * v, l, mid), query(fl, fr, 2 * v + 1, mid + 1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> data[i];

    fillTree(1, 0, n - 1);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r, 1, 0, n - 1) << "\n";
    }
    return 0;
}