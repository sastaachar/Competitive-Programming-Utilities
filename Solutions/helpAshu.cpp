//! segment tree point update
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

const int max_n = 10e5;
int tree[4 * max_n];
int DEF = 0;
int n;
int data[max_n];

int comp(int a, int b) {
    return a + b;
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

void updatePoint(int i, int new_value, int v, int l, int r) {
    if (l == r) {
        tree[v] = new_value;
        return;
    }

    if (i > r || i < l) {
        return;
    };

    int mid = (l + r) / 2;

    if (i <= mid) {
        updatePoint(i, new_value, 2 * v, l, mid);
    } else {
        updatePoint(i, new_value, 2 * v + 1, mid + 1, r);
    }
    tree[v] = comp(tree[2 * v], tree[2 * v + 1]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> data[i];
    for (int i = 0; i < n; i++) data[i] %= 2;
    fillTree(1, 0, n - 1);

    int t;
    cin >> t;
    while (t--) {
        int c, l, r;
        cin >> c >> l >> r;
        //  cout << c << "-" << l << "-" << r << "\n";

        if (c == 0) {
            updatePoint(l - 1, r % 2, 1, 0, n - 1);
        } else if (c == 1) {
            cout << (r - l + 1) - query(l - 1, r - 1, 1, 0, n - 1) << "\n";
        } else {
            cout << query(l - 1, r - 1, 1, 0, n - 1) << "\n";
        }
    }
    return 0;
}
