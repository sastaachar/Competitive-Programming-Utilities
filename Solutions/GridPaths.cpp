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

long long dp[1001][1001];

int fill(int i, int j, int n) {
    if (dp[i][j] == -2) return 0;

    if (dp[i][j] == -1) {
        dp[i][j] = (fill(i, j + 1, n) + fill(i + 1, j, n)) % mod;
    }
    return dp[i][j];
}

void solve() {
    int n;
    cin >> n;

    fr(n, i) {
        fr(n, j) {
            char c;
            cin >> c;
            dp[i][j] = (c == '.') ? -1 : -2;
        }
    }
    if (dp[n - 1][n - 1] == -1) {
        dp[n - 1][n - 1] = 1;
    }

    cout << fill(0, 0, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}