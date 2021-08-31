#include <bits/stdc++.h>
using namespace std;

int solve(int w, int n, int coins[]) {
    if (n == 0 || w == 0) return 0;

    int dp[w + 1];
    for (int i = 0; i <= w; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j >= coins[i]) {
                if ((dp[j - coins[i]]) != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    return dp[w] == INT_MAX ? -1 : dp[w];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    int coins[n];

    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << solve(x, n, coins);

    return 0;
}
