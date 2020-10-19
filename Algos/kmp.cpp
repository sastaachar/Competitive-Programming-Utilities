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

vector<int> getLps(string s) {
    int i = 1, j = 0, len = s.length();

    vector<int> lps(len, 0);
    lps[0] = 0;

    while (i < len) {
        if (s[i] == s[j]) {
            lps[i] = j + 1;
            ++i;
            ++j;
        } else {
            // s[i] != s[j]
            if (j != 0) {
                j = lps[j - 1];
            } else {
                // j == 0
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

vector<int> kmp(string n, string m) {
    // to find m in n

    vector<int> ans;

    vector<int> lps = getLps(m);
    int i = 0, j = 0, nLen = n.length(), mLen = m.length();

    while (i < nLen) {
        if (n[i] == m[j]) {
            ++i;
            ++j;

            if (j == mLen)
                ans.push_back(i - mLen);

        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }

    return ans;
}

int main() {
    cout << "Knuth–Morris–Pratt algorithm\n";

    string n;
    cout << "Enter a string : ";
    cin >> n;

    string m;
    cout << "Enter a substring to search for string : ";
    cin >> m;

    // fund occurrences of m in n
    vector<int> occurrences = kmp(n, m);

    if (occurrences.size() != 0) {
        for (int i = 0; i < occurrences.size(); i++) {
            cout << occurrences[i] << " - " << occurrences[i] + m.length() << "\n";
        }
    } else {
        cout << "There is no \"" << m << "\" in " << n << "\n";
    }

    return 0;
}