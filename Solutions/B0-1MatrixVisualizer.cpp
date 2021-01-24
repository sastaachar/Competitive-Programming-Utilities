#include <bits/stdc++.h>
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
#define vvl vector<vl>
#define fs first
#define ss second
// clang-format off
#define vin(arr,n) ff(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

void solve() {
    int m, n, k;
    cin >> n >> m >> k;

    vvi arr(n, vi(m, 0));

    vector<pii> points;
    ff(k) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        pii lol;
        lol.fs = x;
        lol.ss = y;
        points.pb(lol);
    }

}

void printMat(vvi mat) {
    // clear terminal
    fr(mat.size(), i) {
        fr(mat[i].size(), j)
                cout
            << mat[i][j] << " ";
        cout << "\n";
    }
    // sleep
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}