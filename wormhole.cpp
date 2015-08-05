/*
ID: rohitbo1
PROG: wormhole
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


struct Wormhole {
	int x, y;

	Wormhole(int x, int y) {
		this -> x = x;
		this -> y = y;
	}

	bool operator< (const Wormhole& other) const {
		if (this -> y != other.y) {
			return this -> y < other.y;
		}
		return this -> x < other.x;
	}
};
	static int ct = 0;
bool check_if_infinite_loop(unordered_map<int, int>& indices_map, vector<Wormhole>& sorted_wormholes) {
	set<int> visited_vertices;
	ct++;
	cout << ct << " count\n";
	while (visited_vertices.size() < sorted_wormholes.size()) {
		int cycle_start, n = sorted_wormholes.size();
		for (int i = 1; i <= sorted_wormholes.size(); ++i) {
			if (visited_vertices.find(i) == visited_vertices.end()) {
				cycle_start = i;
				break;
			}
		}
		int cur_vertex = cycle_start;
		set<int> cycle;
		while (true) {
			cout << cur_vertex << " -:- ";
			if (cycle.find(cur_vertex) != cycle.end()) {
				return true;
			}
			visited_vertices.insert(cur_vertex);
			cycle.insert(cur_vertex);
			int warped_vertex = indices_map[cur_vertex];
			if (warped_vertex == n) {
				break;
			} else if (sorted_wormholes[warped_vertex - 1].y == sorted_wormholes[warped_vertex].y) {
				cur_vertex = warped_vertex + 1;
			} else {
				break;
			}
		}
		cout << " --br-- ";
	}
	cout << "\n";
	return false;
}

void count_possible_sums(vector<Wormhole>& sorted_wormholes, int& sum, int n, unordered_map<int, int>& indices_map, int start = 1) {
	if (indices_map.size() == n) {
		for (auto it = indices_map.begin(); it != indices_map.end(); ++it) {
			cout << it -> first << " " << it -> second << ", ";
		}
		cout << "\n:\n";
		int temp = check_if_infinite_loop(indices_map, sorted_wormholes);
		cout << temp << "\n";
		sum += temp;
		return;
	}
	if (indices_map.find(start) != indices_map.end()) {
		count_possible_sums(sorted_wormholes, sum, n, indices_map, start + 1);
		return;
	}
	for (int i = start + 1; i <= n; ++i) {
		if (indices_map.find(i) == indices_map.end()) {
			indices_map[i] = start;
			indices_map[start] = i;
			count_possible_sums(sorted_wormholes, sum, n, indices_map);
			indices_map.erase(start);
			indices_map.erase(i);
		}	
	}	
}


int main() {
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	int n, sum = 0;
	vector<Wormhole> sorted_wormholes;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		fin >> x >> y;
		sorted_wormholes.push_back(Wormhole(x, y));
	}
	sort(sorted_wormholes.begin(), sorted_wormholes.end());
	cout << sorted_wormholes[0].x << " " << sorted_wormholes[1].x << " " << sorted_wormholes[2].x << " " << sorted_wormholes[3].x << "\n";
	unordered_map<int,int> indices_map;
	count_possible_sums(sorted_wormholes, sum, n, indices_map);
	fout << sum << "\n";
	cout << sum << "\n";
	return 0;
}