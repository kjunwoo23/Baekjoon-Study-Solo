#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N;
int idx;

vector<long long> arr;
vector<int> arr2;

void GetArr() {
    long long tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    //sort(arr.begin(), arr.end());
}

long long FindPos(long long start, long long end) {
    //cout << start << " " << end << endl;
    if (start >= end) return start;
    long long mid = floor(start * 0.5 + end * 0.5);
    if (arr[idx] == arr2[mid])
        return mid;
    else if (arr[idx] > arr2[mid])
        return FindPos(mid + 1, end);
    else
        return FindPos(start, mid);
}

int main() {

    cin >> N;
    GetArr();

    arr2.push_back(arr[0]);
    idx++;

    for (int i = 1; i < N; i++) {
        if (arr2.back() < arr[i]) arr2.push_back(arr[i]);
        else {
            int tmp = FindPos(0, arr2.size() - 1);
            arr2[tmp] = arr[i];
        }
            
        idx++;
    }

    cout << arr2.size();

    return 0;
}