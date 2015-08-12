/*
ID: rohitbo1
PROG: frac1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

struct Fraction {
	int numer;
	int denom;

	Fraction(int n, int d) : numer(n), denom(d) {}

	bool operator <(const Fraction&other) const {
		return this -> numer * other.denom < other.numer * this -> denom;
	}

	bool operator ==(const Fraction&other) const {
		return this -> numer * other.denom == other.numer * this -> denom;
	}
};
int main() {
	int n;
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	fin >> n;

	set<Fraction> fractions;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			fractions.insert(Fraction(j, i));
		}
	}

	fout << 0 << "/" << 1 << "\n";

	for (auto& elem: fractions) {
		fout << elem.numer << "/" << elem.denom << "\n";
		cout << elem.numer << "/" << elem.denom << "\n";
	}

	fout << 1 << "/" << 1 << "\n";
	return 0;
}