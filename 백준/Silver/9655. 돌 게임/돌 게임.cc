#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N;
int dp[1001];

int main() {
    init();

    cin >> N;

    dp[1] = dp[3] = 1;    
    dp[2] = 0;

    for (int i = 4; i <= N; i++) {
            dp[i] = 1 - dp[i - 1];
    }

    if (dp[N] == 1)
        cout << "SK";
    else
        cout << "CY";


    return 0;
}