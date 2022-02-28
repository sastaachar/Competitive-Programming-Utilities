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

template <typename T>
vector<int> createDisjointSet(vector<T> arr, bool (*isConnected)(T, T)) {
    int n = arr.size();
    vector<vector<int> > graph(n, vector<int>());

    vector<int> ds(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected(arr[i], arr[j])) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << "  - ";
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << graph[i][j] << ", ";
    //     }
    //     cout << "\n";
    // }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);

        // cout << arr[i] << "  - ";

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            if (visited[top]) continue;
            visited[top] = true;
            ds[top] = i;
            // cout << arr[top] << ", ";

            for (int j = 0; j < graph[top].size(); j++) {
                if (!visited[graph[top][j]])
                    q.push(graph[top][j]);
            }
        }
        // cout << "\n";
    }
    return ds;
}
bool isConnected(int a, int b) {
    return a & b;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr;
        vin(arr, n);

        vi ds = createDisjointSet(arr, isConnected);

        vector<pii> pos;
        for (int i = 0; i < n; i++) {
            pos.pb({arr[i], i});
        }
        sort(pos.begin(), pos.end());

        string ans = "Yes";
        for (int i = 0; i < n; i++) {
            if (ds[pos[i].ss] != ds[i]) {
                ans = "No";
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}