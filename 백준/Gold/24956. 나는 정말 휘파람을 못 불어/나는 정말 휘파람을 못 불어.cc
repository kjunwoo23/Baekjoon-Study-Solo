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
vector<int> W, H, E;
ll ans;

ll dp[200001];

void memo() {
    dp[0] = 1;
    for (int i = 1; i < N + 1; i++)
        dp[i] = (dp[i - 1] * 2) % 1000000007;
}

ll countVariousE(ll n) {
    if (dp[n] - n - 1 < 0)
        return dp[n] - n - 1 + 1000000007;
    return dp[n] - n - 1;
}

int main() {
    init();

    cin >> N;

    memo();

    char tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp == 'W') W.emplace_back(i);
        if (tmp == 'H') H.emplace_back(i);
        if (tmp == 'E') E.emplace_back(i);
    }
    
    ll tmpW, tmpE;
    for (int i = 0; i < H.size(); i++) {
        tmpW = lower_bound(W.begin(), W.end(), H[i]) - W.begin();
        tmpE = E.size() - (lower_bound(E.begin(), E.end(), H[i]) - E.begin());
        tmpE = countVariousE(tmpE);

        ans += (tmpW * tmpE) % 1000000007;
        ans %= 1000000007;
    }
    
    cout << ans;

    return 0;
}