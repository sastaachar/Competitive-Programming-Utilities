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
    void solve(vector<int>& candi, int target, int ele, vector<int> selected, vector<vector<int>>& ans) {
        // if given  [ 2 ,4 ,5 7] and target 10
        // start with  ^
        // i = [1, target/candi[ele]]

        // when to stop
        if (target == 0) {
            // selected has our answer
            ans.push_back(selected);
            return;
        }
        if (ele >= candi.size() || target < candi[ele]) return;

        // what to do
        // chose i candi[ele] and rest from i+1
        for (int i = 0; i <= target / candi[ele]; i++) {
            // take i candi[ele]
            vector<int> temp = selected;
            for (int j = 0; j < i; j++) temp.push_back(candi[ele]);

            // fill rest with others
            solve(candi, target - i * candi[ele], ele + 1, temp, ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;

        solve(candidates, target, 0, vector<int>(), ans);

        return ans;
    }

    void print(vector<vector<int>> ans) {
        // print ans here
    }
};

int main() {
    Solution s;
    // take inputs

    vector<int> candidates;
    int target;
    //call fn
    s.print(s.combinationSum(candidates, target));

    return 0;
}