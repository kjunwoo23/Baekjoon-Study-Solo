#include <iostream>
#include <algorithm> 
#include <vector>
#include <tuple>
using namespace std;

int N;

vector<tuple<long long, long long>> timeSet;

void GetTime() {
	long long start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		timeSet.emplace_back(end, start);
	}
}

void SortTime() {
	sort(timeSet.begin(), timeSet.end());
}

int PackFromNow() {
	int cnt = 0, i = 0;
	int end = -1;
	while (i < N) {
		if (get<1>(timeSet[i]) >= end) {
			end = get<0>(timeSet[i]);
			cnt++;
		}
		i++;
	}
	return cnt;
}


int main() {
	cin >> N;
	GetTime();
	SortTime();
	cout << PackFromNow();

	return 0;
}