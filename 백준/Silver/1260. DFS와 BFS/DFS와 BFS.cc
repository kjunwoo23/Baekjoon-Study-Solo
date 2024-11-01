#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N, M, V;

vector<int> adjNodes[1001];
bool visited[1001];

void DFS(int node) {
    if (visited[node]) return;
    
    visited[node] = true;
    cout << node << ' ';

    for (int i = 0; i < adjNodes[node].size(); i++)
        DFS(adjNodes[node][i]);
}

void BFS(int start) {
    queue<int> waitList;

    waitList.emplace(start);
    visited[start] = true;

    while (!waitList.empty()) {
        int curNode = waitList.front();
        waitList.pop();
        cout << curNode << ' ';

        for (int i = 0; i < adjNodes[curNode].size(); i++) {
            if (visited[adjNodes[curNode][i]]) continue;
            visited[adjNodes[curNode][i]] = true;
            waitList.emplace(adjNodes[curNode][i]);
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> V;
    
    int tmp1, tmp2;
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        adjNodes[tmp1].emplace_back(tmp2);
        adjNodes[tmp2].emplace_back(tmp1);
    }

    for (int i = 1; i <= N; i++)
        sort(adjNodes[i].begin(), adjNodes[i].end());

    DFS(V);

    memset(visited, false, sizeof(visited));
    cout << endl;

    BFS(V);

    return 0;
}
