#include <bits/stdc++.h>
#include <unordered_set>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M, H;
vector<int> blocks[51];
int dp[51][1001];

int jaegui(int student, int curHeight) {
    if (curHeight == H)   return 1;
    if (student >= N) return 0;

    if (dp[student][curHeight] != -1)
        return dp[student][curHeight];

    int tmp = 0;
    for (int i = 0; i < blocks[student].size(); i++) {
        if (curHeight + blocks[student][i] <= H)
            tmp = (tmp + jaegui(student + 1, curHeight + blocks[student][i]) % 10007) % 10007;
    }
    
    dp[student][curHeight] = tmp;
    return tmp;
}

int main() {
    init();

    cin >> N >> M >> H;
    cin.ignore();

    string str;
    for (int i = 0; i < N; i++) {
        getline(cin, str);

        stringstream ss(str);
        string token;

        blocks[i].emplace_back(0);

        while (getline(ss, token, ' '))
            blocks[i].emplace_back(stoi(token));
    }

    memset(dp, -1, sizeof(dp));

    cout << jaegui(0, 0) % 10007;

    return 0;
}