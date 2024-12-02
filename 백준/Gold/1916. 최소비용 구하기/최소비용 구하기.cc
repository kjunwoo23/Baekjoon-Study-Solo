#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int V, E, K, T;
int dist[20001];
vector<pair<int, int>> edges[20001];


void BFS() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitList;

    waitList.emplace(0, K);
    dist[K] = 0;

    while (!waitList.empty()) {
        int curDist = waitList.top().first;
        int curNode = waitList.top().second;
        waitList.pop();

        for (int i = 0; i < edges[curNode].size(); i++) {
            if (dist[edges[curNode][i].second] > curDist + edges[curNode][i].first) {
                dist[edges[curNode][i].second] = curDist + edges[curNode][i].first;
                waitList.emplace(curDist + edges[curNode][i].first, edges[curNode][i].second);

            }
        }
    }
}

int main() {
    init();

    cin >> V >> E;

    int u, v, w;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
    }

    cin >> K >> T;

    for (int i = 1; i <= V; i++)
        sort(edges[i].begin(), edges[i].end());


    fill(&dist[0], &dist[20001], INT_MAX / 2);

    BFS();

    cout << dist[T] << endl;

    return 0;
}