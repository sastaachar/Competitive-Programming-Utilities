#include <bits/stdc++.h>

using namespace std;

const long long mod = (long long)(1e9 + 7);

int n;
vector<long long> coins;

long long dp[1000001];
bool v[1000001] = {0};

long long solve(long long w) {
    if (w < 0) return 0;

    if (!v[w]) {
        long long sum = 0;
        for (int i = 0; i < coins.size(); i++) {
            sum = (sum + solve(w - coins[i])) % mod;
        }
        dp[w] = sum % mod;
        v[w] = 1;
    }

    return dp[w];
}

int main() {
    dp[0] = 1;
    v[0] = 1;

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        coins.push_back(t);
    }
    cout << solve(x);
    return 0;
}