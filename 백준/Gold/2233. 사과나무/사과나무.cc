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
int history[4000];
int X, Y;
deque<int> tree;
deque<int> tmp1, tmp2;
int node;
int needToCut = 1;

int main() {
    init();

    cin >> N;

    char tmp;
    for (int i = 0; i < N * 2; i++) {
        cin >> tmp;
        history[i] = tmp - '0';
    }
    cin >> X >> Y;

    for (int i = 0; i < N * 2; i++) {

        if (history[i] == 0)
            tree.emplace_back(++node);

        if (i == X - 1) tmp1 = tree;
        if (i == Y - 1) tmp2 = tree;

        if (history[i] == 1)
            tree.pop_back();

        if (!tmp1.empty() && !tmp2.empty()) break;
    }
    
    while (!tmp1.empty() && !tmp2.empty()) {
        if (tmp1.front() == tmp2.front()) {
            needToCut = tmp1.front();
            tmp1.pop_front();
            tmp2.pop_front();
        }
        else break;
    }

    tree.clear();
    node = 0;

    for (int i = 0; i < N * 2; i++) {
        if (history[i] == 0) {
            tree.emplace_back(++node);
            if (tree.back() == needToCut)
                cout << i + 1 << ' ';
        }
        if (history[i] == 1) {
            if (tree.back() == needToCut) {
                cout << i + 1 << ' ';
                break;
            }
            tree.pop_back();
        }
    }

    return 0;
}