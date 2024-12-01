#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
ll ans;
ll dp[2001][2001];
ll cake[2001];

int clamp(int i) {
    if (i < 0) return i + N;
    if (i >= N) return i - N;
    return i;
}

ll EatCake(int start, int end) {
    if (clamp(start) == clamp(end + 1)) return 0;
    if (dp[start][end] != -1) return dp[start][end];

    if (cake[clamp(start - 1)] > cake[clamp(end + 1)])
        start = clamp(start - 1);
    else
        end = clamp(end + 1);

    if (clamp(start) == clamp(end + 1)) return 0;
    if (dp[start][end] != -1) return dp[start][end];

    ll tmp1 = cake[clamp(start - 1)] + EatCake(clamp(start - 1), end);
    ll tmp2 = cake[clamp(end + 1)] + EatCake(start, clamp(end + 1));

    dp[start][end] = max(tmp1, tmp2);

    return dp[start][end];
}

int main() {
    init();

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> cake[i];

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
        ans = max(ans, cake[i] + EatCake(i, i));

    cout << ans;
    return 0;
}