#include <bits/stdc++.h>
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(siz, i, a) for (int i = a; i < siz; i++)
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
#define vin(arr,n) ff(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) ff(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
#define top front
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);
using namespace std;

struct node {
    string s;
    int spam; 
    int nSpam;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
      int n;
      map<string, node> cache;
    fe(n) {
    string s;
            bool isSpam ;
        cin >>s;
        cin >> isSpam;

        if( cache.find(s) == cache.end() ) {    

                node temp;
                temp.s= s;
                temp.spam = 0;
                temp.nSpam =0;
                cache[s] = temp;
              
        } 
     if(isSpam)  ++cache[s].spam;
                else        ++cache[s].nSpam;

    }

int count  = 0;
    for(auto itr = cache.begin() ; itr!= cache.end(); itr++) {

        count += max(itr->second.spam,itr->second.nSpam);

    }
    cout << count << "\n";

    }
    return 0;
}