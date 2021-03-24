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

ll solve(vi &arr, ll k, ll n) {
    // find min sum
    ll i, sum = 0, minSum = 0;
    for (i = 0; i < k; i++) {
        sum += arr[i];
    }

    minSum = sum;
    for (ll i = 1; i <= (n - k); i++) {
        sum -= arr[i - 1];
        sum += arr[i + k - 1];

        if (sum < minSum)
            minSum = sum;
    }

    ll total = 0;
    fr(n, i)
        total += arr[i];

    return (total - minSum) + ((minSum * (minSum + 1)) / 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vi arr;
        vin(arr, n);

        cout << solve(arr, k, n) << "\n";
    }
    return 0;
}