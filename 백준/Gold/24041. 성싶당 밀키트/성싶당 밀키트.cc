#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

struct FOOD {
    int S, L;
};

int N, G, K;
vector<FOOD> important;
vector<FOOD> notImportant;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

bool cntGerm(int day) {
    ll totalGerm = 0;

    for (int i = 0; i < important.size(); i++) {
        totalGerm += (ll)important[i].S * max(1, day - important[i].L);
    }

    priority_queue<ll> notImportantPQ;

    for (int i = 0; i < notImportant.size(); i++) {
        totalGerm += (ll)notImportant[i].S * max(1, day - notImportant[i].L);
        notImportantPQ.emplace((ll)notImportant[i].S * max(1, day - notImportant[i].L));
    }

    for (int i = 0; i < K; i++) {
        if (notImportantPQ.empty()) break;
        totalGerm -= notImportantPQ.top();
        notImportantPQ.pop();
    }

    if (totalGerm > G) return false;
    return true;
}

int main() {
    init();

    cin >> N >> G >> K;

    int tmpS, tmpL, tmpO;
    for (int i = 0; i < N; i++) {
        cin >> tmpS >> tmpL >> tmpO;
        if (tmpO == 0) important.push_back({ tmpS, tmpL });
        else notImportant.push_back({ tmpS, tmpL });
    }

    ll l = 0;
    ll r = INT_MAX;

    while (l + 1 < r) {
        if (!cntGerm((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    cout << l;

    return 0;
}