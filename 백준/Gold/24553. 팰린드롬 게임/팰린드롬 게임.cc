#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int T;
ll N;

int main() {
    init();

    cin >> T;
    while (T > 0) {
        T--;

        cin >> N;

        if (N % 10 == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}