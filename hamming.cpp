/*
ID: rohitbo1
PROG: hamming
LANG: C++11
*/
#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int hamming_distance(int first, int second) {
	int sum = 0;
	while (first != 0 || second != 0) {
		sum += (first % 2 != second % 2);
		first = first >> 1;
		second = second >> 1;
	}
	return sum;
}

int main() {
	int n, b, d, cur = 1;
	string output;
	set<int> codewords;

	cout << hamming_distance(0, 7) << "\n\n\n";

	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	fin >> n >> b >> d;
	codewords.insert(0);
	while (codewords.size() < n && cur != 256) {
		bool is_candidate = all_of(codewords.begin(), codewords.end(), [&cur, &d](int word) {return hamming_distance(word, cur) >= d;});
		if (is_candidate) {
			codewords.insert(cur);
		}
		cur++;
	}

	assert(codewords.size() == n);
	int sum = 0;
	for (auto word: codewords) {
		sum++;
		output.append(to_string(word) + ((sum % 10) ? " " : "\n"));
	}
	output.pop_back();
	output.push_back('\n');

	fout << output;

	return 0;
}