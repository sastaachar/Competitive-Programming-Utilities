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
//ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

////////MO's algo/////////
ll SQRT_N = 141;
struct qry {
    int L, R, i;
};
//to store data
int bucket[1000001] = {0};
ll ans = 0;

bool cmp(qry a, qry b) {
    if (a.L / SQRT_N != b.L / SQRT_N)
        return a.L < b.L;
    return a.R < b.R;
}
void addE(int data) {
    //cout<<"Add "<<data<<"\n";
    ans += (2 * bucket[data] + 1) * data;
    ++bucket[data];
}
void removE(int data) {
    //cout<<"Remove "<<data<<"\n";
    ans += (1 - 2 * bucket[data]) * data;
    --bucket[data];
}
////////MO's algo/////////

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, qsize;
    cin >> n >> qsize;
    vl arr;
    vin(arr, n);

    //    SQRT_N = sqrt(n);
    vector<qry> qrys;
    fr(qsize, i) {
        qry tmp;
        cin >> tmp.L >> tmp.R;
        tmp.L--;
        tmp.R--;
        tmp.i = i;
        qrys.pb(tmp);
    }
    sort(qrys.begin(), qrys.end(), cmp);
    vl qans(qsize);
    int curL = qrys[0].L, curR = qrys[0].L;
    addE(arr[curL]);
    for (auto &q : qrys) {
        //cout<<q.L<<" "<<q.R<<" ";
        while (curL < q.L)
            removE(arr[curL++]);

        while (curL > q.L)
            addE(arr[--curL]);

        while (curR < q.R)
            addE(arr[++curR]);

        while (curR > q.R)
            removE(arr[curR--]);

        qans[q.i] = ans;
        //cout<<ans<<"\n";
    }

    fr(qsize, i) {
        cout << qans[i] << "\n";
    }

    return 0;
}
