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

    bool solve(vector<int>& candidates, int target, vector<int> solution, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.pb(solution);
            return true;
        }

        fr(candidates.size(), )
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        return ans;
    }

    void print(vector<vector<int>> ans) {
        // print ans here
        fr(ans.size(), i)
            pv(ans[i])
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    // take inputs
    int n;
    cin >> n;
    vector<int> candidates;
    int target;
    vin(candidates, n);
    cin >> target;
    //call fn
    s.print(s.combinationSum(candidates, target));

    return 0;
}