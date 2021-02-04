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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vi arr;
    int n, k;
    cin >> n >> k;
    vin(arr, n);

    int sum = 0;

    for (size_t i = 0; i < n; i++) {
        if (arr[i] <= arr[k - 1]) ++sum;
    }

    cout << sum;

    return 0;
}