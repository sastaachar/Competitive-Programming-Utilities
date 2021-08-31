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

template <typename X>
string show(X data) {
    return to_string(data);
}
string show(pair<int, int> data) {
    return "{" +
           to_string(data.first) + "," +
           to_string(data.second) + "}";
}
template <typename X>
string print(vector<X> data) {
    string ans = "[";
    for (auto x : data)
        ans += " " + show(x) + ",";
    ans += "]";
    return ans;
}
template <typename X, typename Y>
string print(map<X, Y> data) {
    string ans = "[";
    for (auto x : data)
        ans += " " + show(x) + ",";
    ans += "]";
    return ans;
}d
