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
int step[301];
int dp[301][3];


int main() {
    init();

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> step[i + 1];
    }

    for (int i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + step[i];
        dp[i][2] = dp[i - 1][1] + step[i];
    }

    cout << max(dp[N][1], dp[N][2]);

    return 0;
}