#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

string str;
int leftKCnt, leftRCnt;
int rightKCnt, rightRCnt;

int rCnt;

int ans;

int main() {
    init();
    cin >> str;

    for (auto iter = str.begin(); iter != str.end(); iter++)
        if (*iter == 'R') rCnt++;
    
    ans = rCnt;

    auto iterL = str.begin(), iterR = str.end() - 1;
    while (iterL < iterR) {
        while (*iterL == 'K' && iterL < iterR)
            leftKCnt++, iterL++;
        while (*iterR == 'K' && iterL < iterR)
            rightKCnt++, iterR--;

        ans = max(ans, min(leftKCnt, rightKCnt) * 2 + rCnt - leftRCnt - rightRCnt);

        if (leftKCnt < rightKCnt)
            while (*iterL == 'R' && iterL < iterR)
                leftRCnt++, iterL++;
        else
            while (*iterR == 'R' && iterL < iterR)
                rightRCnt++, iterR--;

        //ans = max(ans, min(leftKCnt, rightKCnt) * 2 + rCnt - leftRCnt - rightRCnt);
    }

    cout << ans;

    return 0;
}