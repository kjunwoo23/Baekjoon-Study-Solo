#include <iostream>
#include <algorithm> 
#include <vector>
#include <tuple>
using namespace std;

int N;

string input;
int num[50];
char sym[50];
int i = 0;

int FindNum(char* p) {
	int num = 0;
	while (*p != '+' && *p != '-' && *p != '\0') {
		num *= 10;
		num += *p - '0';
		p++;
	}
	return num;
}

int Calculate(int ii, bool minus) {
	if (ii >= i) return num[ii];
	if (minus) return num[ii] + Calculate(ii + 1, true);

	if (sym[ii] == '+') return num[ii] + Calculate(ii + 1, false);
	else return num[ii] - Calculate(ii + 1, true);
}


int main() {
	int ans;
	cin >> input;

	char* s = &(input[0]);
	int size = input.length();

	while (s < &(input[0]) + size) {
		num[i] = FindNum(s);
		while ('0' <= *s && *s <= '9')
			s++;
		if (s >= &(input[0]) + size) break;
		sym[i] = *s;
		s++;
		i++;
	}


	cout << Calculate(0, false);

	return 0;
}