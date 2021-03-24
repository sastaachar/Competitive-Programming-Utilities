// ! https://atcoder.jp/contests/arc112/tasks/arc112_b

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
const int maxn = (int)(10e5 + 1);
const ll mod = (ll)(1e9 + 7);
using namespace std;

// useless question

/*
ll getK(ll b, ll c, ll n) {
    if (c & 1) {
        if (b < 0)
            return 2 * min(n, b * -1);
        return (n >= b) ? 2 * b - 1 : 2 * n;
    } else {
        if (b < 0)
            return (n - 1 >= b * -1) ? 2 * b * -1 - 1 : 2 * (n - 1);
        return 2 * min(b, n) - 2;
    }
}

ll solve(ll b, ll c) {
    ll n = c / 2;
    if (b == 0) return c;
    if (c == 1) return 1 + (b != 0);
    return 2 * n + getK(b, c, n) + 1;
}
*/

ll getK(ll b, ll c, ll n) {
    if (c & 1) {
        if (b < 0)
            return 2 * min(n, b * -1);
        return min(2 * b - 1, 2 * n);
    } else {
        if (b < 0)
            return min(2 * b * -1, 2 * n - 1) - 1;
        return 2 * min(b, n) - 2;
    }
}

ll solve(ll b, ll c) {
    ll n = c / 2;
    if (b == 0) return c;
    if (c == 1) return 1 + (b != 0);
    return 2 * n + getK(b, c, n) + 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll b, c;
    cin >> b >> c;
    cout << solve(b, c) << "\n";
    return 0;
}
