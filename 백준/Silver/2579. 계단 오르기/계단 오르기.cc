#include <bits/stdc++.h>

using namespace std;

int N;
int points[301];
int memo[301][3];

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i < N + 1; i++)
        cin >> points[i];

    memo[1][1] = points[1];
    memo[1][2] = points[1];

    for (int i = 2; i <= N; i++) {
        memo[i][0] = max(memo[i - 1][1], memo[i - 1][2]);
        memo[i][1] = memo[i - 1][0] + points[i];
        memo[i][2] = memo[i - 2][0] + points[i - 1] + points[i];
    }

    cout << max(memo[N][1], memo[N][2]);

    return 0;
}
