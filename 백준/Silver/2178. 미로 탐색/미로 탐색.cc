#include <bits/stdc++.h>
using namespace std;

char route[101][101] = { 0 };
int dist[101][101] = { 0 };
bool visited[101][101] = { 0 };
int N, M;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void inputRoute() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> route[i][j];
        }
    }
}

void getDistance() {
    queue<pair<int, int>> container;

    container.emplace(0, 0);

    while (!container.empty()) {
        pair<int, int> nowPos = container.front();
        container.pop();

        int i = nowPos.first;
        int j = nowPos.second;

        if (i == N - 1 && j == M - 1) continue;

        if (visited[i][j]) continue;
        visited[i][j] = true;

        for (int d = 0; d < 4; d++) {
            if (0 <= i + dy[d] && i + dy[d] < N)
                if (0 <= j + dx[d] && j + dx[d] <M) {
                    if (!visited[i + dy[d]][j + dx[d]] && route[i + dy[d]][j + dx[d]] == '1') {
                        container.emplace(i + dy[d], j + dx[d]);
                        dist[i + dy[d]][j + dx[d]] = min(dist[i + dy[d]][j + dx[d]], dist[i][j] + 1);
                    }
                }
        }
    }
}

int main() {

    cin >> N >> M;

    fill(&dist[0][0], &dist[N][M], INT_MAX);
    dist[0][0] = 1;

    inputRoute();
    getDistance();

    cout << dist[N - 1][M - 1];


    return 0;
}