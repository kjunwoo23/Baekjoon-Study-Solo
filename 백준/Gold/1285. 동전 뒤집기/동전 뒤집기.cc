#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <climits>
using namespace std;

int N;

int coins[20][20];
int totalRowCoins[20];
int totalColCoins[20];

int coinsBackUp[20][20];
int totalRowCoinsBackUp[20];
int totalColCoinsBackUp[20];

void inputCoins() {
    char tmp;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            if (tmp == 'H')
                coins[i][j] = 0;
            if (tmp == 'T')
                coins[i][j] = 1;
            coinsBackUp[i][j] = coins[i][j];
        }
}

void resetCoins() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            coins[i][j] = coinsBackUp[i][j];
    for (int i = 0; i < N; i++) {
        totalRowCoins[i] = totalRowCoinsBackUp[i];
        totalColCoins[i] = totalColCoinsBackUp[i];
    }
}

void sumRow(int i) {
    int sum = 0;
    for (int j = 0; j < N; j++)
        sum += coins[i][j];
    totalRowCoins[i] = sum;
}

void sumCol(int j) {
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += coins[i][j];
    totalColCoins[j] = sum;
}

void initTotalCoins() {
    for (int i = 0; i < N; i++) {
        sumRow(i);
        sumCol(i);
        totalRowCoinsBackUp[i] = totalRowCoins[i];
        totalColCoinsBackUp[i] = totalColCoins[i];
    }
}

void flipRow(int i) {
    for (int j = 0; j < N; j++) {
        if (coins[i][j] == 1)
            totalColCoins[j]--;
        else
            totalColCoins[j]++;
        coins[i][j] = 1 - coins[i][j];
    }
    totalRowCoins[i] = N - totalRowCoins[i];
}

void flipCol(int j) {
    for (int i = 0; i < N; i++) {
        coins[i][j] = 1 - coins[i][j];
        if (coins[i][j] == 1)
            totalRowCoins[i]--;
        else
            totalRowCoins[i]++;
    }
    totalColCoins[j] = N - totalColCoins[j];
}

int main() {

    cin >> N;
    inputCoins();
    initTotalCoins();

    int realAns = N * N;
    for (int i = 0; i < pow(2, N); i++)
    {
        int tmpI = i;
        for (int cnt = 0; cnt < N; cnt++) {
            if (tmpI % 2 == 1)
                flipRow(cnt);
            tmpI /= 2;
        }
        for (int j = 0; j < N; j++)
            if (totalColCoins[j] > N / 2)
                flipCol(j);

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += totalColCoins[i];

        ans = min(ans, N * N - ans);
        realAns = min(ans, realAns);

        resetCoins();
    }

    cout << realAns;

    return 0;
}