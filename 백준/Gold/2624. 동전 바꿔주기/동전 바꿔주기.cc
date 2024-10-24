#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int t, k;
vector<pair<int, int>> coins;
long long memo[10002];

void ChangeCoin() {
    memo[0] = 1;

    // 동전 종류마다 경우의 수 + 1
    // 뒤에서 앞으로 오면서 동전 개수만큼 경우의 수 더하기
    for (int i = 0; i < k; i++) {
        for (int j = t; j >= 0; j--)
            for (int coinNum = 1; coinNum <= coins[i].second; coinNum++) {
                if (coins[i].first * coinNum > j) break;
                memo[j] += memo[j - coins[i].first * coinNum];
            }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    cin >> t >> k;
    int tmp1, tmp2;
    for (int i = 0; i < k; i++) {
        cin >> tmp1 >> tmp2;
        coins.emplace_back(tmp1, tmp2);
    }
    //sort(coins.begin(), coins.end());

    ChangeCoin();

    cout << memo[t];
    return 0;
}