#include <bits/stdc++.h>

using namespace std;

const long long mod = (long long)(1e9 + 7);

long long dp[1000001];

long long solve(long long w, vector<long long> &coins) {
    int n = coins.size();

    // fill bottom
    for (int j = 0; j <= w; j++) {
        dp[j] = !(j % coins[n - 1]);
    }

    if (n > 1) {
        for (int i = n - 2; i >= 0; i--) {
            for (long long j = 1; j <= w; j++) {
                if (j < coins[i]) {
                    dp[j] = 0;
                    continue;
                }
                dp[j] = (dp[j - coins[i]] + dp[j]) % mod;
            }
        }
    }

    return dp[w];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<long long> coins;
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        coins.push_back(t);
    }
    sort(coins.begin(), coins.end());

    cout << solve(x, coins);
    return 0;
}