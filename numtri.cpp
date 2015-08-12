/*
ID: rohitbo1
PROG: numtri
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;


int main () {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int r;
	fin >> r;

	cout << r << "\n\n";

	vector<int> row;
	vector<int> max_previous, cur_max;

	max_previous.clear();

	for (int i = 0; i < r; ++i) {
		row.clear();
		cur_max.clear();
		for (int j = 0; j <= i; ++j) {
			int temp;
			fin >> temp;
			row.push_back(temp);
		}
		if (row.size() == 1) {
			cur_max = row;
		} else {
			assert(row.size() == i + 1);
			assert(max_previous.size() == i);
			for (int j = 0; j <= i; ++j) {
				cur_max.push_back(max(max_previous[max(j-1, 0)],
									  max_previous[min(i - 1, j)]) + row[j]);
			}
		}
		max_previous = cur_max;
	}

	for (auto elem : cur_max) {
		cout << elem << " ";
	}
	cout << "\n";
	int elt =  *max_element(cur_max.begin(), cur_max.end());
	cout << elt << "\n";
	fout << elt << "\n";
	return 0;
}