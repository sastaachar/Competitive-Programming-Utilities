//! https://acm.timus.ru/problem.aspx?space=1&num=1930

#include <bits/stdc++.h>
#define fr(siz, i) for (int i = 0; i < siz; i++)
#define frr(a, siz, i) for (int i = a; i < siz; i++)
#define fe(siz) for (int sasta = 0; sasta < siz; sasta++)
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pib pair<int, bool>
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
const int INF = INT_MAX;
const int MAXN = (int)(2e5 + 5);
const ll MOD = (ll)(1e9 + 7);
using namespace std;

// 0 -> up
// 1 -> down

typedef vector<vector<pib>> Graph;
typedef pair<int, pib> Cost;

int findCost(int source, int destination, Graph &graph, bool up) {
    priority_queue<Cost, vector<Cost>, greater<Cost>> q;
    vector<int> weights(graph.size(), INF);
    vector<bool> visited(graph.size(), 0);

    q.push({0, {source, up}});
    weights[source] = 0;

    while (!q.empty()) {
        Cost cur = q.top();
        q.pop();

        int cost = cur.first, v = cur.second.first,
            dir = cur.second.second;

        visited[v] = true;

        for (auto child : graph[v]) {
            int u = child.first, cdir = child.second;
            int curCost = cost + (cdir != dir);
            if (!visited[u] && weights[u] > curCost) {
                weights[u] = curCost;
                q.push({curCost, child});
            }
        }
    }

    return weights[destination];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pib>> graph(n + 1, vector<pib>());

    fr(m, i) {
        int u, v;
        cin >> u >> v;
        graph[u].pb({v, 0});
        graph[v].pb({u, 1});
    }

    int source, destination;
    cin >> source >> destination;

    int ans = min(findCost(source, destination, graph, 0),
                  findCost(source, destination, graph, 1));

    cout << ans;
    return 0;
}