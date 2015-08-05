/*
ID: rohitbo1
PROG: skidesign
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int DIFF = 17;

int main() {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	int n;
	vector<int> heights, changed_heights;

	fin >> n;
	for (int i = 0; i < n; ++i) {
		int height;
		fin >> height;
		heights.push_back(height);
	}

	//Identify the solution space which is a superset of the actual solutions
	//Solution space: The final heights of the hill can belong to intervals like
	// [0, 17] [1, 18],...........[83, 100]//
	int min_cost = INT_MAX;
	for (int start_elev = 0; start_elev < 84; start_elev++) {
		int end_elev = start_elev + DIFF, cost = 0;
		for (int i = 0; i < heights.size(); ++i) {
			if (heights[i] < start_elev) {
				cost += ((start_elev - heights[i]) * (start_elev - heights[i]));
			}
			if (heights[i] > end_elev) {
				cost += ((heights[i] - end_elev) * (heights[i] - end_elev));
			}
		}
		min_cost = min(cost, min_cost);
	}

	fout << min_cost << "\n";
	cout << min_cost << "\n";

}
