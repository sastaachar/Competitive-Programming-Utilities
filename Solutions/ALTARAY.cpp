#include <bits/stdc++.h>
using namespace std;
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(siz, i, a) for (int i = a; i < siz; i++)
#define ff(siz) for (int sasta = 0; sasta < siz; sasta++)
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
// ios_base::sync_with_stdio(0);cin.tie(0);
// clang-format off
#define vin(arr,n) ff(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
// clang-format on
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vl arr;
        vln(arr, n);
        int ans[n];
        ans[n - 1] = 1;
        for (int i = n - 2; i >= 0; i++)
            ans[i] = arr[i] * arr[i + 1] < 0 ? ans[i + 1] + 1 : 1;

        fr(n, i)
                cout
            << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}