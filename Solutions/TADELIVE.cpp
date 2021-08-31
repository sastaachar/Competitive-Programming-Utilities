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
    int n, ac, bc;
    cin >> n >> ac >> bc;

    vi A, B;
    vin(A, n);
    vin(B, n);

    vector<pii> diff;
    fr(n, i) {
        diff.pb({abs(A[i] - B[i]), i});
    }
    sort(diff.begin(), diff.end(), greater<pii>());

    int sum = 0;
    fr(n, idx) {
        int i = diff[idx].ss;

        if (A[i] > B[i] && ac > 0) {
            sum += A[i], --ac;
            continue;
        } else if (B[i] > A[i] && bc > 0) {
            sum += B[i], --bc;
            continue;
        }

        sum += ac ? A[i] : B[i];
    }

    cout << sum << "\n";

    return 0;
}