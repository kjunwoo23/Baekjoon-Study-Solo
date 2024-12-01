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
vector<pair<ll, int>> T;
int maxCnt;
ll TEm, TXm;

int main() {
    init();

    cin >> N;

    ll tmpE, tmpX;
    for (int i = 0; i < N; i++) {
        cin >> tmpE >> tmpX;
        T.emplace_back(tmpE, 1);
        T.emplace_back(tmpX, -1);
    }

    sort(T.begin(), T.end());

    int curCnt = 0;
    ll curTime = 0;
    bool isMax = false;
    for (int i = 0; i < T.size(); i++) {
        if (curTime != T[i].first) {
            if (curCnt > maxCnt) {
                isMax = true;
                maxCnt = curCnt;
                TEm = curTime;
            }
            else if (curCnt < maxCnt && isMax) {
                isMax = false;
                TXm = curTime;
            }
            curTime = T[i].first;
        }

        if (T[i].second == 1) curCnt++;
        else curCnt--;
    }

    if (isMax) TXm = curTime;

    cout << maxCnt << endl;
    cout << TEm << ' ' << TXm;
    return 0;
}