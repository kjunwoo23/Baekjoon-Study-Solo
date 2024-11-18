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
int cntMemo[100001];

int ans = 0;

int main() {
    init();

    cin >> str;

    int stackSize = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            stackSize++;
        else if (str[i] == ')')
            stackSize--;
        cntMemo[i] = stackSize;
    }

    if (cntMemo[str.size() - 1] == -2) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ')') ans++;
            if (cntMemo[i] < 0) break;
        }
    }
    else if (cntMemo[str.size() - 1] == 2) {
        for (int i = str.size() - 1; i >= 0; i--) {
            if (cntMemo[i] < 2) break;
            if (str[i] == '(') ans++;
        }
    }

    cout << ans;

    return 0;
}