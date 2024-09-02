#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <climits>
using namespace std;

int N;

vector<int> san;
vector<int> alc;
vector<int> liq;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void GetLiq() {
    long long tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        liq.push_back(tmp);
        if (tmp > 0) san.push_back(tmp);
        else alc.push_back(tmp);
    }
    if (!san.empty())
        sort(san.begin(), san.end());
    if (!alc.empty())
        sort(alc.begin(), alc.end());
    sort(liq.begin(), liq.end());
}


int FindMinimumSet(int data, int start, int end) {
    if (start >= end) return start;
    long long mid = floor(start * 0.5 + end * 0.5);
    if (data + liq[mid] == 0)
        return mid;
    else if (data + liq[mid] < 0)
        return FindMinimumSet(data, mid + 1, end);
    else
        return FindMinimumSet(data, start, mid);
}

void FindLiq() {
    for (int i = 0; i < liq.size(); i++) {
        int tmp = FindMinimumSet(liq[i], 0, liq.size() - 1);
        pq.emplace(abs(liq[i] + liq[tmp]), i, tmp);
        if (tmp > 0) pq.emplace(abs(liq[i] + liq[tmp - 1]), i, tmp - 1);
        if (tmp < liq.size() - 1) pq.emplace(abs(liq[i] + liq[tmp + 1]), i, tmp + 1);
    }  
}

int main() {

    cin >> N;
    GetLiq();

    if (alc.empty()) cout << san[0] << ' ' << san[1];
    else if (san.empty()) cout << alc[alc.size() - 2] << ' ' << alc[alc.size() - 1];

    else {
        FindLiq();
        while (get<1>(pq.top()) == get<2>(pq.top()))
            pq.pop();
        cout << min(liq[get<1>(pq.top())], liq[get<2>(pq.top())]);
        cout << ' ';
        cout << max(liq[get<1>(pq.top())], liq[get<2>(pq.top())]);
    }
    return 0;
}