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

bool isSet(int n, int k) {
    return n & (1 << (k - 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi arr;
    vin(arr, n);

    int dp[32][n];

    fr(32, i) {
        dp[i][n - 1] = isSet(arr[n - 1], i + 1);
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1] + isSet(arr[j], i + 1);
        }
    }

    ll sum = 0, pow = 1;
    fr(n, j) {
        fr(32, i) {
            if (isSet(arr[j], i + 1)) {
                sum = sum + (dp[i][j] - 1) * pow;
            }
            pow *= 2;
        }
        pow = 1;
    }

    cout << sum << "\n";

    return 0;
}