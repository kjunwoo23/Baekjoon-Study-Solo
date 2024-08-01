#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int N;
int waitTimes[1000];

void GetWaitTime() {
	for (int i = 0; i < N; i++) {
		cin >> waitTimes[i];
	}
}

int CountTime() {
	int ans = 0;
	sort(waitTimes, waitTimes + N);

	for (int i = 0; i < N; i++)
		ans += waitTimes[i] * (N - i);

	return ans;
}


int main() {
	cin >> N;
	GetWaitTime();
	cout << CountTime();

	return 0;
}