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

void solve() {
    int n, m, ik;
    cin >> n >> m >> ik;
    ll arr[n][m];
    fr(n, i) fr(m, j) cin >> arr[i][j];

    ll dp[n + 1][m + 1];

    fr(n + 1, i) dp[i][0] = 0;
    fr(m + 1, j) dp[0][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + arr[i][j];

    int count = 0;

    fr(n, i) {
        fr(m, j) {
            long long sum = 0;
            bool gotIt = false;
            int maxk = min(n - i - 1, m - j - 1);

            int l = 0, r = maxk, foundK = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                sum = dp[i + mid + 1][j + mid + 1] -
                      dp[i][j + 1 + mid] - dp[i + 1 + mid][j] + dp[i][j];
                int c = mid + 1;
                long long avg = sum / (c * c);
                if (avg >= ik) {
                    // if found store and go  left
                    foundK = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (foundK != -1) {
                count += (maxk - foundK + 1);
            }
        }
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}