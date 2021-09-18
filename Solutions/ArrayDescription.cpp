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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vl arr;
    vln(arr, n);

    vvl dp(n, vl(m + 2, 0));

    if (arr[0] == 0) {
        frr(1, m + 1, i) dp[0][i] = 1;
    } else {
        dp[0][arr[0]] = 1;
    }

    // dp[i][x] = dp[i-1][x] + dp[i-1][x+1] + dp[i-1][x-1]
    frr(1, n, i) {
        if (arr[i] == 0) {
            frr(1, m + 1, x) {
                dp[i][x] = (dp[i - 1][x] + dp[i - 1][x + 1] + dp[i - 1][x - 1]) % mod;
            }
        } else {
            dp[i][arr[i]] = (dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1] + dp[i - 1][arr[i] - 1]) % mod;
        }
    }

    ll sum = 0;
    if (arr[n - 1] == 0) {
        frr(1, m + 1, i) sum = (sum + dp[n - 1][i]) % mod;
    } else {
        sum = dp[n - 1][arr[n - 1]];
    }

    cout << sum << "\n";

    return 0;
}