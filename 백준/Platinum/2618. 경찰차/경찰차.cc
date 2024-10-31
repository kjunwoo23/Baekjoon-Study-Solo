#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, W;
pair<int, int> cases[1001];
int dp[1001][1001];

// 두 사건 사이 거리 계산
int calcDist(int case1, int case2) {
    int x, y;
    if (case1 == -1) {
        x = 1 - cases[case2].first;
        y = 1 - cases[case2].second;
    }
    else if (case1 == -2) {
        x = N - cases[case2].first;
        y = N - cases[case2].second;
    }
    else {
        x = cases[case1].first - cases[case2].first;
        y = cases[case1].second - cases[case2].second;
    }
    return abs(x) + abs(y);
}

// 경찰차1이 a사건, 경찰차2가 b사건 해결했을 때 사건 종결까지 최소한의 경로
int writeDP(int a, int b) {
    if (a == W || b == W) return 0;
    if (dp[a][b] != -1) return dp[a][b];

    int next = max(a, b) + 1;

    int tmp1 = writeDP(next, b);    // 다음 사건을 경찰차1이 해결
    int tmp2 = writeDP(a, next);    // 다음 사건을 경찰차2가 해결

    if (a == 0) tmp1 += calcDist(-1, next);
    else tmp1 += calcDist(a, next);
    if (b == 0) tmp2 += calcDist(-2, next);
    else tmp2 += calcDist(b, next);

    dp[a][b] = min(tmp1, tmp2);

    return dp[a][b];
}

void printDP(int a, int b) {
    if (a == W || b == W) return;

    int next = max(a, b) + 1;

    int tmp1, tmp2;

    // (a, b)부터 사건 종결까지의 거리 (단, 바로 다음 사건은 경찰차 1이 해결)
    if (a != 0)    tmp1 = dp[next][b] + calcDist(a, next);
    else    tmp1 = dp[next][b] + calcDist(-1, next);

    // (a, b)부터 사건 종결까지의 거리 (단, 바로 다음 사건은 경찰차 2가 해결)
    if (b != 0)    tmp2 = dp[a][next] + calcDist(b, next);
    else    tmp2 = dp[a][next] + calcDist(-2, next);

    if (tmp1 < tmp2) {
        cout << 1 << endl;
        printDP(next, b);
    }
    else {
        cout << 2 << endl;
        printDP(a, next);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    cin >> N >> W;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= W; i++)
        cin >> cases[i].first >> cases[i].second;

    cout << writeDP(0, 0) << endl;

    printDP(0, 0);

    return 0;
}