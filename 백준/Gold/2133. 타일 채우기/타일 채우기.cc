#include <iostream>
using namespace std;

int memo[31] = { 0 };

int tiling(int N) {
    if (memo[N] != 0) return memo[N];
    if (N == 0) return 1;
    if (N % 2 == 1) return 0;
    if (N == 2) return 3;

    int ans = 3 * tiling(N - 2);

    int tmpN = N;
    while (tmpN >= 4) {
        ans += tiling(tmpN - 4) * 2;
        tmpN -= 2;
    }

    memo[N] = ans;
    return ans;
}

int main() {
    int N;
    int ans;
    cin >> N;

    cout << tiling(N);

    return 0;
}