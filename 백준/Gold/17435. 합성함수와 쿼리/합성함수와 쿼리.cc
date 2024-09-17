#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cstdlib>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define make_unique(v) v.erase(unique(v.begin(), v.end()), v.end())
typedef long long ll;
using namespace std;

int table[500001][22];
int m, q, n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> table[i][0];

    for (int j = 1; j < 22; j++)
        for (int i = 1; i <= m; i++)
            table[i][j] = table[table[i][j - 1]][j - 1];

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> n >> x;
        for (int j = 0; j < 22; j++)
            if (n & (1<<j)) x = table[x][j];
        cout << x << "\n";
    }

    return 0;
}