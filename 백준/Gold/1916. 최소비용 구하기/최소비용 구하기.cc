#include <bits/stdc++.h>

using namespace std;

int N, M, start, fin;
vector<pair<int, int>> edges[100001];

int dist[1001];

void BFS() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty()) {
        int curPrice = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curPrice > dist[curNode]) continue;

        for (int i = 0; i < edges[curNode].size(); i++) {
            if (dist[edges[curNode][i].second] > dist[curNode] + edges[curNode][i].first) {
                dist[edges[curNode][i].second] = dist[curNode] + edges[curNode][i].first;
                pq.emplace(dist[edges[curNode][i].second], edges[curNode][i].second);
            }            
        }
    }
}


int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    fill(&dist[0], &dist[N] + 1, INT_MAX / 2);

    int tmp1, tmp2, tmp3;
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        edges[tmp1].emplace_back(tmp3, tmp2);
    }

    cin >> start >> fin;

    BFS();

    cout << dist[fin];

    return 0;
}
