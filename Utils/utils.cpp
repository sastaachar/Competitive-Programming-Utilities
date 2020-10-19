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
// clang-format off
#define vin(arr,n) ff(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
// clang-format on
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

// random number generators
vi get_n_random(int n, int r = 10e5, int l = 0) {
    vi randomNumbers;
    ff(n) randomNumbers.pb(rand() % r + l);
    return randomNumbers;
}
int get_1_random(int r = 10e9, int l = 0) {
    return rand() % r + l;
}
string get_1_random_string(int len = 20) {
    string s = "";
    ff(len) {
        s += (char)('a' + get_1_random() % 26);
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "This is util file";
    return 0;
}