#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N;
long long M;

vector<int> woods;

void GetWoods() {
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        woods.push_back(tmp);
    }
    sort(woods.begin(), woods.end());
}

long long CalcWoods(int height) {
    long long total = 0;
    for (int i = 0; i < N; i++)
        if (woods[i] > height)
            total += woods[i] - height;
    return total;
}

int FindHeight(int start, int end) {
    //cout << start << " " << end << endl;
    if (start >= end) return start;
    int mid = ceil((start + end) * 0.5);
    if (CalcWoods(mid) == M)
        return mid;
    else if (CalcWoods(mid) > M)
        return FindHeight(mid, end);
    else
        return FindHeight(start, mid - 1);
}

int main() {

    cin >> N >> M;
    GetWoods();

    cout << FindHeight(0, woods[N - 1]);

    return 0;
}