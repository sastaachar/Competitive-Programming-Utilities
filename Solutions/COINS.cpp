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

map<ll, ll> memo;

ll fn(ll n) {
    if (n < 12) return n;
    if (!memo[n])
        memo[n] = max(fn(n / 2) + fn(n / 3) + fn(n / 4), n);
    return memo[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (cin >> n) {
        cout << fn(n) << "\n";
    }
    return 0;
}