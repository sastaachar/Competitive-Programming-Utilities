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
#define pvp(arr) fr(arr.size(),i){cout<<arr[i].first<<" - "<<arr[i].second<<", ";}cout<<"\n";
// clang-format on
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int N, X;
        cin >> N >> X;
        vi arr;
        vin(arr, X);

        vector<pii> ranges;
        pii firstRange{1, 2 * N};
        ranges.pb(firstRange);
        N = 2 * N;
        fr(X, i) {
            //cout << "start half\n";
            pvp(ranges);
            int r = arr[i];

            r = r % N;

            int index;
            while (r > 0) {
                index = ranges.size() - 1;
                int count = ranges[index].second - ranges[index].first + 1;

                if (count > r) {
                    // need to split
                    pii newRange{ranges[index].second - r + 1, ranges[index].second};
                    ranges[index].second = ranges[index].second - r;
                    ranges.insert(ranges.begin(), newRange);
                    r = 0;
                } else {
                    // need more
                    ranges.insert(ranges.begin(), ranges[index]);
                    ranges.erase(ranges.end());
                    r -= count;
                }
            }

            //cout << "rotating half\n";
            pvp(ranges);

            // remove N/2
            r = (N + 2 - 1) / 2, index = ranges.size() - 1;
            while (r > 0) {
                index = ranges.size() - 1;
                int count = ranges[index].second - ranges[index].first + 1;

                if (count > r) {
                    // need to split
                    ranges[index].second = ranges[index].second - r;
                    r = 0;
                } else {
                    // need more
                    ranges.erase(ranges.end());
                    r -= count;
                }
            }
            cout << "removing half\n";
            pvp(ranges);

            N = N - (N + 2 - 1) / 2;

            if (ranges.size() == 1 && ranges[0].second - ranges[0].first == 0)
                break;
        }

        if (ranges.size() == 1 && ranges[0].second == ranges[0].first) {
            cout << ranges[0].first << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
