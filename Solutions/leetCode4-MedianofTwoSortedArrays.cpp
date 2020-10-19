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

// random number generators
vi get_n_random(int n, ll r = 10e9, ll l = 0) {
    vi randomNumbers;
    ff(n) randomNumbers.pb(rand() % r + l);
    return randomNumbers;
}
int get_1_random(ll r = 10e9, ll l = 0) {
    return rand() % r + l;
}

class Solution {
   public:
    // function here
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            Ideal conditions :
        
            x1 x2 x3 | x4 x5 x6 x7

            y0 y1 y2 y3 y4 y5 |  y6 y7 y8 y9  

            x3 <= y6
            y5 <= x4
    
    
            x3 = x on left   -  xl 
            x4 = x on right  -  xr 
            y5 = y on left   -  yl 
            x6 = y on right  -  yr 

            (variables are name using this)

        */

        int m = nums1.size(), n = nums2.size();

        if (m < n) {
            // nums2 should always be smaller
            return findMedianSortedArrays(nums2, nums1);
        }
        pv(nums1);
        pv(nums2);
        // nums2 is always smaller

        int l = 0, r = n, xr, xl, yr, yl;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            xr = mid;
            xl = xr - 1;

            yr = (n + m - 2 * mid) / 2;
            yl = yr - 1;
            cout << xr << " " << yr << "\n";
            xl = (xr == 0) ? INT_MIN : nums2[xl];
            xr = (xr == n) ? INT_MAX : nums2[xr];
            yl = (yr == 0) ? INT_MIN : nums1[yl];
            yr = (yr == m) ? INT_MAX : nums1[yr];

            if (xl <= yr && yl <= xr) {
                // got the point

                cout << xl << "," << xr << "\t" << yl << "," << yr << "\n";
                if ((m + n) % 2) {
                    // odd

                    return (double)min(xr, yr);
                } else {
                    // even

                    return (double)(max(xl, yl) + min(xr, yr)) / 2;
                }
            } else if (yr > xl) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << "Fucked\n";
        return 0;
    }

    double brute(vector<int>& nums1, vector<int>& nums2) {
        vi nums3;
        nums3.insert(nums3.end(), nums1.begin(), nums1.end());
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        int mid = nums3.size() / 2;

        if (nums3.size() % 2 == 0) {
            return (double)(nums3[mid] + nums3[mid - 1]) / 2;
        } else {
            return nums3[mid];
        }
    }

    double test(int t) {
        srand(time(0));
        Solution s;

        int count = 0;
        ff(t) {
            vi nums1 = get_n_random(get_1_random(10, 1), 100);
            vi nums2 = get_n_random(get_1_random(10, 1), 100);
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            double ans1 = s.brute(nums1, nums2), ans2 = s.findMedianSortedArrays(nums1, nums2);

            if (abs(ans1 - ans2) <= 0.00001) {
                cout << "Brute : " << ans1 << "\t\t"
                     << "Solve : " << ans2 << "\n";
            } else {
                ++count;
            }
        }

        cout << "Pass % - " << (double)(t - count) / t << "\n";
    };

    void print(double ans) {
        // print ans here
        cout << ans << "\n";
    }
};

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    Solution s;
    // take inputs
    s.test(200);
    //call fn

    return 0;
}