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

// niceeeeeeeeeeeeeeeeeeeeeeee
int getPos(vl &arr, int val) {
    int l = 0, r = arr.size() - 1, m;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= val)
            r = m - 1;
        else
            l = m + 1;
    }

    if (arr[l] >= val) --l;
    return l;
}

int lis(vl arr) {
    int n = arr.size();

    int length = 1;

    vl dp(n + 1, INT_MAX);
    dp[0] = -1;

    fr(n, i) {
        const int pos = getPos(dp, arr[i]);
        if (pos == -1) {
            dp[1] = min(dp[1], arr[i]);
        } else {
            // arr[i] at m+1
            dp[pos + 1] = min(arr[i], dp[pos + 1]);
            length = max(length, pos + 1);
        }
    }

    return length;
}

int main() {
    int n;
    cin >> n;

    vl arr;
    vln(arr, n);

    cout << lis(arr);
}