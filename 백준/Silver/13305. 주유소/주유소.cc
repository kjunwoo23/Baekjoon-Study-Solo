#include <iostream>
#include <algorithm> 
#include <vector>
#include <tuple>
using namespace std;

int N;

long long dist[100000], price[100000];

int main() {
	long long  ans = 0;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}

	for (int i = 0; i < N; i++)
		cin >> price[i];

	long long curPrice = price[0];

	for (int i = 0; i < N - 1; i++) {
		if (curPrice > price[i])
			curPrice = price[i];
		ans += curPrice * dist[i];
	}

	cout << ans;

	return 0;
}