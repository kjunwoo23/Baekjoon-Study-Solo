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
string name;
string abba;

bool MakeABBA() {
	int centerPos = name.size() / 2;
	int abbaIdx = 0;
	bool onlyOnce = false;
	for (int i = 0; i < name.size() && abbaIdx <= centerPos; ) {
		char a, b;
		a = name[i];
		if (i + 1 >= name.size())
			if (onlyOnce)
				return false;
			else {
				onlyOnce = true;
				abba[centerPos] = a;
				return true;
			}
		b = name[i + 1];

		if (a != b)
			if (!onlyOnce && name.size() % 2 != 0) {
				onlyOnce = true;
				if (!name.find(b, i + 2)) {
					abba[centerPos] = b;
					name[i] = b;
					name[i + 1] = a;
				}
				else
					abba[centerPos] = a;
				i++;
				continue;
			}
			else
				return false;
		else {
			abba[abbaIdx] = a;
			abba[name.size() - 1 - abbaIdx] = a;
			abbaIdx++;
			i += 2;
		}
	}
	return true;
}

int main() {

	cin >> name;
	abba = name;

	sort(name.begin(), name.end());

	if (MakeABBA())
		cout << abba;
	else
		cout << "I'm Sorry Hansoo";

	return 0;
}