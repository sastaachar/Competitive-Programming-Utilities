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
const ll N = 1000001;
using namespace std;

ll dp[N][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // calculate for all

    dp[1][0] = 1;
    dp[1][1] = 1;

    frr(2, N, i) {
        dp[i][0] = ((2 * dp[i - 1][0]) % mod + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][0] + (4 * dp[i - 1][1]) % mod) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << "\n";
    }
    return 0;
}