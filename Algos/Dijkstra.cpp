//  q : https://www.spoj.com/problems/SHPATH/

#include <bits/stdc++.h>
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(a, siz, i) for (int i = a; i < siz; i++)
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
#define vin(arr,n) fe(n){int x; cin>>x; arr.pb(x);}
#define vln(arr,n) fe(n){ll x; cin>>x; arr.pb(x);}
#define pv(arr) fr(arr.size(),i){cout<<arr[i]<<" ";}cout<<"\n";
// clang-format on
const int maxn = (int)(2e5 + 5);
const ll mod = (ll)(1e9 + 7);

using namespace std;

typedef vector<vector<pii>> Graph;
void Dijkstra(int source, vi &weights, Graph graph) {
    weights[source] = 0;

    bool visited[weights.size()] = {0};
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, source});

    while (!q.empty()) {
        pii cur = q.top();
        q.pop();
        if (visited[cur.ss]) continue;
        visited[cur.ss] = true;

        for (pii path : graph[cur.ss]) {
            weights[path.ss] = min(weights[path.ss],
                                   weights[cur.ss] + path.ff);
            if (!visited[path.ss])
                q.push({weights[path.ss], path.ss});
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<string, int> mapNameToIdx;
    Graph graph(n, vector<pii>());

    fr(n, i) {
        string name;
        cin >> name;
        mapNameToIdx[name] = i;
        int m;
        cin >> m;
        fr(m, j) {
            int source, cost;
            cin >> source >> cost;
            graph[i].pb({cost, source - 1});
        }
    }

    int r;
    cin >> r;
    vvi weights(n, vi(n, INT_MAX));
    fr(r, i) {
        string source, destination;
        cin >> source >> destination;
        const int sourceIdx = mapNameToIdx[source],
                  destinationIdx = mapNameToIdx[destination];
        if (weights[sourceIdx][sourceIdx] != 0) {
            Dijkstra(sourceIdx, weights[sourceIdx], graph);
        }

        cout << weights[sourceIdx][destinationIdx] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}