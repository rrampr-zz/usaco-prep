/*
ID: rohitbo1
PROG: milk3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <set>
#include <cassert>
#include <sstream>

using namespace std;

bool visited_states[21][21][21];

struct State {
	State(int x, int y, int z) : a(x), b(y), c(z) {}
	int a;
	int b;
	int c;
};

int main() {
	int capa, capb, capc;
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	stringstream output;

	fin >> capa >> capb >> capc;
	cout << capa << capb << capc << "\n";
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			for (int k = 0; k < 21; ++k) {
				visited_states[i][j][k] = false;
			}
		}
	}
	stack<State> path;
	set<int> solutions;
	//Now do dfs
	State start = State(0, 0, capc);
	path.push(start);

	while (!path.empty()) {
		State cur_state = path.top();
		path.pop();
		assert(cur_state.a <= capa && cur_state.b <= capb && cur_state.c <= capc);
		if (visited_states[cur_state.a][cur_state.b][cur_state.c]) {
			continue;
		}
		visited_states[cur_state.a][cur_state.b][cur_state.c] = true;
		if (cur_state.a == 0) {
			solutions.insert(cur_state.c);
		}

		//Now examine neighbours
		if (cur_state.a != 0) {
			if (cur_state.a + cur_state.b <= capb) {
				path.push(State(0, cur_state.a + cur_state.b, cur_state.c));
			} else {
				path.push(State(cur_state.a + cur_state.b - capb, capb, cur_state.c));
			}
			if (cur_state.a + cur_state.c <= capc) {
				path.push(State(0, cur_state.b, cur_state.a + cur_state.c));
			} else {
				path.push(State(cur_state.a + cur_state.c - capc, cur_state.b, capc));
			}
		}

		if (cur_state.b != 0) {
			if (cur_state.b + cur_state.c <= capc) {
				path.push(State(cur_state.a, 0, cur_state.c + cur_state.b));
			} else {
				path.push(State(cur_state.a, cur_state.b + cur_state.c - capc, capc));
			}
			if (cur_state.a + cur_state.b <= capa) {
				path.push(State(cur_state.a + cur_state.b, 0, cur_state.c));
			} else {
				path.push(State(capa, cur_state.b + cur_state.a - capa, cur_state.c));
			}
		}

		if (cur_state.c != 0) {
			if (cur_state.a + cur_state.c <= capa) {
				path.push(State(cur_state.c + cur_state.a, cur_state.b , 0));
			} else {
				path.push(State(capa, cur_state.b, cur_state.a + cur_state.c - capa));
			}
			if (cur_state.b + cur_state.c <= capb) {
				path.push(State(cur_state.a, cur_state.c + cur_state.b, 0));
			} else {
				path.push(State(cur_state.a, capb, cur_state.b + cur_state.c - capb));
			}
		}
	}

	for (auto elem : solutions) {
		output << elem << " ";
	}
	string ans = output.str();
	ans.pop_back();
	ans.push_back('\n');
	fout << ans;
	return 0;
}