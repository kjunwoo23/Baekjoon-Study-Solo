#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N;
int K;

vector<long long> lans;

void GetLans() {
    long long tmp;
    for (int i = 0; i < K; i++) {
        cin >> tmp;
        lans.push_back(tmp);
    }
    sort(lans.begin(), lans.end());
}

long long CalcLans(long long length) {
    long long n = 0;
    for (int i = 0; i < K; i++)
        n += lans[i] / length;
    return n;
}

long long FindLength(long long start, long long end) {
    //cout << start << " " << end << endl;
    if (start >= end) return start;
    long long mid = ceil(start * 0.5 + end * 0.5);
    if (CalcLans(mid) >= N)
        return FindLength(mid, end);
    else
        return FindLength(start, mid - 1);
}

int main() {

    cin >> K >> N;
    GetLans();

    cout << FindLength(1, lans[K - 1]);

    return 0;
}