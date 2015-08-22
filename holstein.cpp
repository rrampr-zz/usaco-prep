/*
ID: rohitbo1
PROG: holstein
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <set>
#include <string>

using namespace std;

int cow[1000];
int feeds[15][1000];
int cur_nutrients[1000];

set<int> sol_feeds;

int main() {
	int v, g;
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");

	fin >> v;
	for (int i = 0; i < v; ++i) {
		fin >> cow[i];
	}
	fin >> g;
	for (int i = 0; i < g; ++i) {
		for (int j = 0; j < v; ++j) {
			fin >> feeds[i][j];
		}
	}

	for (int i = 1; i < 32770; ++i) {
		int temp = i;
		set<int> candidate_feeds;
		for (int k = 0; k < v; ++k) {
			cur_nutrients[k] = -1 * cow[k];
		}

		for (int j = 0; j < g; ++j) {
			int value = temp % 2;
			if (value == 1) {
				candidate_feeds.insert(j);
				for (int k = 0; k < v; ++k) {
					cur_nutrients[k] += feeds[j][k];
				}
			}
			temp >>= 1;
		}

		if ((!sol_feeds.empty() && sol_feeds.size() < candidate_feeds.size())) {
			continue;
		}

		bool satisfies_cow = true;
		for (int k = 0; k < v; ++k) {
			if (cur_nutrients[k] < 0) {
				satisfies_cow = false;
				break;
			}
		}

		if (!satisfies_cow) {
			continue;
		}

		if (sol_feeds.size() == candidate_feeds.size()) {
			bool is_candidate_better = false;
			for (auto it = sol_feeds.begin(), it1 = candidate_feeds.begin(); 
				it != sol_feeds.end() && it1 != candidate_feeds.end(); it++, it1++) {
				if (*it < *it1) {
					break;
				}
				if (*it1 < *it) {
					is_candidate_better = true;
					break;
				}
			}
			if (is_candidate_better) {
				sol_feeds = candidate_feeds;
			}
			continue;
		}
		sol_feeds = candidate_feeds;	
	}


	//output
	string output;
	output.append(to_string(sol_feeds.size()) + " ");
	cout << sol_feeds.size() << " ";
	for (auto elem : sol_feeds) {
		cout << elem + 1 << " ";
		output.append(to_string(elem + 1) + " ");
	}
	output.pop_back();
	output.push_back('\n');
	cout << "\n";
	fout << output;

	return 0;
}