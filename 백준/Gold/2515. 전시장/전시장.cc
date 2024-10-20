#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long N, S;
long long dp[300001][2];
vector<pair<long long, long long>> drawings;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> S;

    long long H, C;
    for (int i = 0; i < N; i++) {
        cin >> H >> C;
        drawings.emplace_back(H, C);
    }

    sort(drawings.begin(), drawings.end());

    dp[0][1] = drawings[0].second;

    for (int i = 1; i < N; i++) {

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        int limit = upper_bound(drawings.begin(), drawings.begin() + i, make_pair(drawings[i].first - S, (long long)1001)) - drawings.begin() - 1;
        
        if (limit < 0)
            dp[i][1] = drawings[i].second;
        else
            dp[i][1] = max(dp[limit][0], dp[limit][1]) + drawings[i].second;
    }

    cout << max(dp[N - 1][0], dp[N - 1][1]);

    return 0;
}