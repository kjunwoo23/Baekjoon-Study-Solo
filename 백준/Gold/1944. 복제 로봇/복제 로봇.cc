#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <climits>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
#include <map>

#define endl "\n"
#pragma warning(disable:4996)
using namespace std;

int N, M;
struct pos {
    int x;
    int y;
};
char route[51][51] = { 0 };
int dist[51][51] = { 0 };
bool visited[51][51] = { 0 };

pos keys[251];
int keyDist[251][251];

bool impossible;

vector<tuple<int, int, int>> edges;
int parent[251];

int ans = 0;

// 부모 찾기
int FindParent(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = FindParent(parent[x]);
}

// 이미 선택된 숫자는 바롣 다음 숫자랑 부모 합치기
void UnionParent(int x, int y) {
    x = FindParent(x);
    y = FindParent(y);
    parent[y] = x;
}

void inputRoute() {
    fill(&route[0][0], &route[50][50], 1);
    int k = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> route[i][j];
            if (route[i][j] == 'S') {
                keys[0].x = j;
                keys[0].y = i;
            }
            if (route[i][j] == 'K') {
                keys[k].x = j;
                keys[k].y = i;
                k++;
            }
        }
    }
}

void getDistance(int keyNum) {
    queue<pos> container;

    fill(&dist[0][0], &dist[N][N], INT_MAX / 2);
    fill(&visited[0][0], &visited[N][N], false);

    dist[keys[keyNum].y][keys[keyNum].x] = 0;
    container.push({ keys[keyNum].x, keys[keyNum].y });

    while (!container.empty()) {
        pos nowPos = container.front();
        container.pop();

        int i = nowPos.y;
        int j = nowPos.x;

        if (i == N - 1 && j == N - 1) continue;

        if (visited[i][j]) continue;
        visited[i][j] = true;

        if (i > 0)
            if (!visited[i - 1][j] && route[i - 1][j] != '1') {
                container.push({ j, i - 1 });
                dist[i - 1][j] = min(dist[i - 1][j], dist[i][j] + 1);
            }
        if (i < N - 1)
            if (!visited[i + 1][j] && route[i + 1][j] != '1') {
                container.push({ j, i + 1 });
                dist[i + 1][j] = min(dist[i + 1][j], dist[i][j] + 1);
            }
        if (j > 0)
            if (!visited[i][j - 1] && route[i][j - 1] != '1') {
                container.push({ j - 1, i });
                dist[i][j - 1] = min(dist[i][j - 1], dist[i][j] + 1);
            }
        if (j < N - 1)
            if (!visited[i][j + 1] && route[i][j + 1] != '1') {
                container.push({ j + 1, i });
                dist[i][j + 1] = min(dist[i][j + 1], dist[i][j] + 1);
            }
    }
    for (int i = 0; i <= M; i++) {
        keyDist[keyNum][i] = dist[keys[i].y][keys[i].x];
        if (keyDist[keyNum][i] == INT_MAX / 2) {
            keyDist[keyNum][i] = -1;
            impossible = true;
            return;
        }
    }
}

void showPath() {
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            cout << keyDist[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> M;

    inputRoute();
    for (int i = 0; i <= M; i++)
        getDistance(i);

    for (int i = 0; i <= M; i++) {
        parent[i] = i;
        for (int j = i + 1; j <= M; j++) {
            edges.emplace_back(keyDist[i][j], i, j);
        }
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        int length = get<0>(edges[i]);
        int cur = get<1>(edges[i]);
        int next = get<2>(edges[i]);

        if (FindParent(cur) == FindParent(next)) continue;
        UnionParent(cur, next);
        ans += length;
        cnt++;
    }

    if (impossible) cout << -1;
    else cout << ans;

    return 0;
}