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
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;
long long my_ceil(long long a, long long b) {
    if (a == 0) return 1;
    return (a + b - 1) / b;
}

void solve() {
    int n;
    cin >> n;

    vi L(n);
    vector<pii> data(n);
    fr(n, i)
        data[i] = {0, i},
        cin >> data[i].ff;

    fr(n, i) cin >> L[i];

    int count = 0;
    sort(data.begin(), data.end());

    int min = data[0].ss;
    frr(n, i, 1) {
        if (data[i].ss <= min) {
            int jumps = my_ceil(min - data[i].ss + 1, L[data[i].ss]);
            count += jumps;
            min = data[i].ss + jumps * (L[data[i].ss]);
        } else {
            min = data[i].ss;
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