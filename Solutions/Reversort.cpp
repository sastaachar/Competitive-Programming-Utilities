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
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

int solve(vi &arr, int n) {
    int cost = 0;
    fr(n - 1, i) {
        // find min indx
        int minIdx = i;
        frr(i + 1, n, j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        // reverse it
        cost += (minIdx - i + 1);
        reverse(arr.begin() + i, arr.begin() + minIdx + 1);
    }

    return cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    frr(1, t + 1, test_case) {
        int n;
        cin >> n;
        vi arr;
        vin(arr, n);
        cout << "Case #" << test_case << ": ";
        cout << solve(arr, n) << "\n";
    }
    return 0;
}