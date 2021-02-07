//! lazy segment tree

#include <bits/stdc++.h>
#define fr(siz, i) for (ll i = 0; i < siz; i++)
#define frr(siz, i, a) for (ll i = a; i < siz; i++)
#define fe(siz) for (ll sasta = 0; sasta < siz; sasta++)
#define ll long long
#define pb push_back
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define ss second
#define ff first
// clang-format off
#define vin(arr,n) fe(n){ll x; cin>>x; arr.pb(x);}
#define vln(arr,n) fe(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
#define top front
const ll maxn = (ll)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

const ll max_n = 100000;
pii tree[4 * max_n + 1];
ll lzytree[4 * max_n + 1];
pii DEF = {0, 0};
ll n;
ll data[max_n];

pii updateComp(ll l, ll r, ll val, pii cur) {
    val %= 3;
    if (val == 1) {
        return {(r - l + 1) - (cur.first + cur.second), cur.first};
    } else if (val == 2) {
        return {cur.second, (r - l + 1) - (cur.first + cur.second)};
    }
    return cur;
}
pii comp(pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}

void clearLzy(ll v, ll l, ll r) {
    tree[v] = updateComp(l, r, lzytree[v], tree[v]);

    // update child's value
    if (l != r) {
        // non leaf
        lzytree[2 * v] += lzytree[v], lzytree[2 * v + 1] += lzytree[v];
    }
    lzytree[v] = 0;
}

void updateRange(ll fl, ll fr, ll v, ll l, ll r) {
    if (lzytree[v]) {
        // clear lazy first
        clearLzy(v, l, r);
    }

    if (fl > r || fr < l) return;

    if (fl <= l && fr >= r) {
        // update this

        tree[v] = updateComp(l, r, 1, tree[v]);

        if (l != r) {
            // non leaf
            ++lzytree[2 * v], ++lzytree[2 * v + 1];
        }

        return;
    }

    ll mid = (l + r) / 2;
    updateRange(fl, fr, 2 * v, l, mid);
    updateRange(fl, fr, 2 * v + 1, mid + 1, r);
    tree[v] = comp(tree[2 * v], tree[2 * v + 1]);
}
pii query(ll fl, ll fr, ll v, ll l, ll r) {
    if (lzytree[v]) {
        // clear lazy first
        clearLzy(v, l, r);
    }

    if (fl <= l && fr >= r) {
        return tree[v];
    }

    if (fl > r || fr < l) return DEF;

    ll mid = (l + r) / 2;
    return comp(query(fl, fr, 2 * v, l, mid), query(fl, fr, 2 * v + 1, mid + 1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll q;
    cin >> q;
    while (q--) {
        ll c, l, r;
        cin >> c >> l >> r;
        if (c) {
            pii ans = query(l, r, 1, 0, n - 1);
            cout << (r - l + 1) - (ans.first + ans.second) << "\n";
        } else {
            updateRange(l, r, 1, 0, n - 1);
        }
    }

    return 0;
}
