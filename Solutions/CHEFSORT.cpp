#include <bits/stdc++.h>
#define fr(siz, i) for (ll i = 0; i < siz; i++)
#define frr(a, siz, i) for (ll i = a; i < siz; i++)
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi arr;
        vin(arr, n);

        ll count = 0;
        fr(n - 1, i) if (arr[i] > arr[i + 1])++ count;

        string ans = "";
        int opCount = 0;
        if (count > (n / 2)) {
            // find max
            ll k = (1 << 30) - 1;
            ans += "4 1 " + to_string(k) + "\n";
            fr(n, i) arr[i] ^= k;
            ++opCount;
        }

        fr(n - 1, i) {
            if (arr[i] > arr[i + 1]) {
                ll k = arr[i] - arr[i + 1];
                ans += "2 " + to_string(i + 2) + " " + to_string(k) + "\n";
                ++opCount;
            }
        }

        cout << opCount << "\n";
        cout << ans;
    }
    return 0;
}