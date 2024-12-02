#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M, V;
vector<int> edges[1001];
bool visited[1001];

void DFS(int v) {
    if (visited[v]) return;
    visited[v] = true;

    cout << v << ' ';

    for (int i = 0; i < edges[v].size(); i++) {
        DFS(edges[v][i]);
    }
}

void BFS(int v) {
    queue<int> waitList;

    waitList.emplace(v);
    visited[v] = true;

    while (!waitList.empty()) {
        int tmpV = waitList.front();
        waitList.pop();

        cout << tmpV << ' ';

        for (int i = 0; i < edges[tmpV].size(); i++) {
            if (!visited[edges[tmpV][i]]) {
                visited[edges[tmpV][i]] = true;
                waitList.emplace(edges[tmpV][i]);
            }
        }
    }
}

int main() {
    init();

    cin >> N >> M >> V;

    int tmp1, tmp2;
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        edges[tmp1].emplace_back(tmp2);
        edges[tmp2].emplace_back(tmp1);
    }

    for (int i = 1; i < N + 1; i++)
        sort(edges[i].begin(), edges[i].end());

    DFS(V);

    fill(visited, visited + N + 1, false);
    cout << endl;

    BFS(V);

    return 0;
}