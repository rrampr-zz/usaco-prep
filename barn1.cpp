#include <iostream>

using namespace std;

struct Interval {
	Interval(int s, int e) : start(s), end(e) {}
	int start;
	int end;
};


int main() {
	fstream f_input("barn1.in");
	fstream f_output("barn1.out");

	int m, s, c;
	f_input >> m >> s >> c;
	vector<int> cows;
	vector<Interval> candidate_cuts;
	for (int i = 0; i < c; ++i) {
		int temp;
		f_input >> temp;
		cows.push_back(temp);
	}
	sort(cows.begin(), cows.end());

	int 
	vector<int> spaces;


	return 0;
}