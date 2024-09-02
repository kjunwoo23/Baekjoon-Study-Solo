#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N;
int C;

vector<long long> houses;

void GetHouses() {
    long long tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        houses.push_back(tmp);
    }
    sort(houses.begin(), houses.end());
}

bool CheckPossible(int length) {
    int lastC = houses[0];
    int tmpC = C - 1;
    for (int i = 0; i < N; i++) {
        if (houses[i] - lastC >= length) {
            lastC = houses[i];
            tmpC--;
        }
        if (tmpC <= 0) return true;
    }
    return false;
}

long long FindLength(long long start, long long end) {
    //cout << start << " " << end << endl;
    if (start >= end) return start;
    long long mid = ceil(start * 0.5 + end * 0.5);
    if (CheckPossible(mid))
        return FindLength(mid, end);
    else
        return FindLength(start, mid - 1);
}

int main() {

    cin >> N >> C;
    GetHouses();

    cout << FindLength(0, houses[N - 1]);

    return 0;
}