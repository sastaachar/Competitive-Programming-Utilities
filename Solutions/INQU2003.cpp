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
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

class Solution {
   public:
    // function here
    int solve(string s1, string s2) {
    }

    void print(int ans) {
        // print ans here
    }

    int brute(string s1, string s2) {
    }

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    }

    int combine(vector<pair<int, int>> ranges) {
        sort(ranges.begin(), ranges.end(), cmp);

        int i = 0;
        while (i < ranges.size()) {
            if (ranges.size() < 2) break;

            if (ranges[i].second >= ranges[i + 1].first - 1) {
                // conbine
                ranges[i + 1].first = ranges[i].first;
                ranges.erase(ranges.begin() + i);
                --i;
            }
            ++i;
        }

        // check

        if (ranges.size() == 1) {
            return (ranges[0].second - ranges[0].first) * 2;
        } else {
            int large = 0, slarge = 0;

            for (int i = 0; i < ranges.size(); i++) {
                int count = ranges[i].second - ranges[i].first + 1;

                if (count > (ranges[large].second - ranges[large].first + 1)) {
                    slarge = large;
                    large = i;
                }
            }
            return (ranges[large].second - ranges[large].first + 1) +
                   (ranges[slarge].second - ranges[slarge].first + 1);
        }

        return 0;
    }
};

int main() {
    Solution s;
    // take inputs

    //call fn

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> arr;
        ff(n) {
            pii p;
            cin >> p.first >> p.second;
            arr.pb(p);
        }

        cout << s.combine(arr) << "\n";
    }

    return 0;
}