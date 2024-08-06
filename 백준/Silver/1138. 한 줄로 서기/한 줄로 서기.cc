#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <list>
#include <set>
#include <map>
using namespace std;

int N;
int tallerLeft[10];
int pos[10];

int main() {
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> tallerLeft[i];

	for (int i = 0; i < N; i++) {
		int shift = tallerLeft[i];
		int x = 0;
		while (shift > 0 || pos[x] != 0) {
			if (pos[x] == 0)
				shift--;
			x++;
		}
		pos[x] = i + 1;
	}

	for (int i = 0; i < N; i++)
		cout << pos[i] << " ";

	return 0;
}