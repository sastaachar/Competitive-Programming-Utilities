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

typedef pair<int, pii> pp;
priority_queue<pp, vector<pp>, greater<pp>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int minCap, maxCap;
    int inputs[400][400];
    while (t--) {
        minCap = INT_MAX, maxCap = INT_MIN;
        int n, m, k;
        cin >> n >> m >> k;
        fr(n, i) fr(m, j) { cin >> inputs[i][j],
                            maxCap = max(maxCap, inputs[i][j]),
                            minCap = min(minCap, inputs[i][j]); }

        vector<pair<pii, pii>> graph[n][m];

        const int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        map<char, int> mapURDL = {{'U', 0}, {'R', 3}, {'D', 2}, {'L', 1}};

        fr(n, i) {
            string s;
            cin >> s;
            fr(m, j) {
                if (i == n - 1 && j == m - 1) continue;
                const int dir = mapURDL[s[j]];
                fr(4, k) {
                    graph[i][j].pb({{(dir + k) % 4, inputs[i][j] - (dir + k) % 4},
                                    {i + offset[k][0], j + offset[k][1]}});
                }
            }
        }

        int left = minCap - 3, right = maxCap;

        int finalAnswer = 0;

        while (right >= left) {
            int mid = left + (right - left) / 2;

            int weights[n][m] = {0};
            bool visited[n][m] = {{0}};
            fr(n, i) fr(m, j) weights[i][j] = INT_MAX, visited[i][j] = 0;

            weights[0][0] = 0;
            weights[n - 1][m - 1] = INT_MAX;

            q.push({0, {0, 0}});

            while (!q.empty()) {
                pp cur = q.top();
                q.pop();
                if (visited[cur.ss.ff][cur.ss.ss])
                    continue;

                visited[cur.ss.ff][cur.ss.ss] = true;
                int i = cur.ss.ff, j = cur.ss.ss;

                for (int paths = 0; paths < graph[cur.ss.ff][cur.ss.ss].size(); paths++) {
                    pair<pii, pii> path = graph[cur.ss.ff][cur.ss.ss][paths];

                    int newI = path.ss.ff, newJ = path.ss.ss;
                    if (newI < 0 || newI >= n || newJ < 0 || newJ >= m)
                        continue;

                    if (path.ff.ss >= mid) {
                        if (weights[newI][newJ] > weights[i][j] + path.ff.ff) {
                            // update state
                            weights[newI][newJ] = weights[i][j] + path.ff.ff;
                        }

                        if (!visited[newI][newJ]) {
                            q.push({weights[newI][newJ], {newI, newJ}});
                        }
                    }
                }
            }

            if (weights[n - 1][m - 1] <= k) {
                left = mid + 1;
                finalAnswer = mid;
            } else {
                right = mid - 1;
            }
        }
        cout << finalAnswer << "\n";
    }
    return 0;
}