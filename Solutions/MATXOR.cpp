#include <bits/stdc++.h>
#define fr(siz, i) for (ll i = 0; i < siz; i++)
#define frr(siz, i, a) for (ll i = a; i < siz; i++)
#define fe(siz) for (ll sasta = 0; sasta < siz; sasta++)
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
#define vin(arr,n) fe(n){ll x; cin>>x; arr.pb(x);}
#define vln(arr,n) fe(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
#define top front
const ll maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

ll sumOfSQ(ll n, ll k) {
    ll ans = 0;
    frr(n + 1, i, 1) {
        ans = ans ^ (k + 2 * i);
    }
    return ans;
}

ll getXOR(int n) {
    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;

    return 0;
}

ll sumOfSingle(ll n, ll m, ll k) {
    ll ans = 0;

    frr(m + 1, i, n + 1) {
        ans = ans ^ (getXOR(k + i) ^ getXOR(k + i + n));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll t1, t2, k;
        cin >> t1 >> t2 >> k;
        ll n = min(t1, t2), m = max(t1, t2);

        if (m != n)
            cout << (sumOfSQ(n, k) ^ sumOfSingle(n, m, k)) << "\n";
        else
            cout << sumOfSQ(n, k) << "\n";
    }
    return 0;
}