/*
ID: rohitbo1
PROG: sprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> is_prime(100000001, true);
vector<int> super_primes;

void gen_primes(int num) {
	int e = sqrt(num);
	for (int i = 2; i <= e; ++i) {
		if (!is_prime[i]) {
			continue;
		}
		is_prime[i] = true;
		for (int k = i; k * i <= num ;++k) {
			is_prime[k * i] = false;
		}
	}
	is_prime[1] = false;
}


bool is_prime_number(int number) {
	if (number == 1) {
		return false;
	}
	if (!(number % 2)) {
		return number == 2;
	}
	int e = sqrt(number);
	for (int i = 3; i <= e; i += 2) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}


void gen_super_primes(int depth, int num = 0) {
	if (depth == 0) {
		super_primes.push_back(num);
		return;	
	}

	for (int i = 1; i < 10; ++i) {
		if (!is_prime_number(num * 10 + i)) {
			continue;
		}
		gen_super_primes(depth - 1, num * 10 + i);
	}
}

int main() {
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");

	int n;
	fin >> n;
	int num = 1;
	for (int i = 1; i <= n; ++i) {
		num = num * 10;
	}
	//gen_primes(100000001);
	gen_super_primes(n);

	for (int i = 0; i < super_primes.size(); ++i) {
		fout << super_primes[i] << "\n";
		cout << super_primes[i] << "\n";
	}
	return 0;
}