/*
ID: rohitbo1
PROG: ariprog
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

struct AP {
	AP(): start(-1), diff(-1) {}
	AP(int s, int d) : start(s), diff(d) {}
	int start;
	int diff;
};

bool comparator(const AP& first, const AP& second) {
	if (first.diff == second.diff) {
		return first.start < second.start;
	}
	return first.diff < second.diff;
}

int solutions[125001];
int differences[10000];
bool bisquares[125001];
AP progressions[10000];

int main() {
	int n, m, ct = 0, num_squares = 0;
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");

	fin >> n >> m;

	for (int i = 0; i < 125001; ++i) {
		bisquares[i] = false;
	}

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (!bisquares[i*i + j*j]) {
				solutions[num_squares++] = i*i + j*j;
			}
			bisquares[i*i + j*j] = true;
		}
	}

	cout << num_squares << "\n";

	for (int i = 0; i < num_squares; ++i) {
		if (ct >= 10000) {
			break;
		}
		for (int j = i + 1; j < num_squares; ++j) {
			int difference = abs(solutions[j] - solutions[i]);
			int greater = max(solutions[j], solutions[i]);

			bool is_arithmetic = true;
			for (int k = 1; k <= n - 2; ++k) {
				if (!bisquares[greater + k * difference]) {
					is_arithmetic = false;
					break;
				}
			}
			if (is_arithmetic) {
				progressions[ct] = AP(min(solutions[i], solutions[j]), difference);
				ct++;
			}
		}
	}

	if (ct == 0) {
		fout << "NONE\n";
	}

	cout << ct << "\n";

	sort(progressions, progressions + ct, comparator);
	for (int i = 0; i < ct; ++i) {
		fout << progressions[i].start << " " << progressions[i].diff << "\n";
	}

	return 0;
}