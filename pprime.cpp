/*
ID: rohitbo1
PROG: pprime
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <deque>
#include <cmath>
#include <vector>

using namespace std;

//100 million is 10^8. So we need to generate palindromes of length 8. so 4 digits uniquely determine it. So we have 10^4 = 10,000 palindromes
vector<int> palindromes;

void gen_palindromes_helper(deque<int>& digits, int depth, bool odd = false, bool leading_digit = false) {
	//should use recursion but hacky and fast to get the answer 
	if (depth == 0) {
		int num = 0;
		if (digits[0] % 2 == false) {
			return;
		}
		for (int i = 0; i < digits.size(); ++i) {
			num = num * 10 + digits[i];
		}
		for (int i = digits.size() - 1 - odd; i >= 0; --i) {
			num = num * 10 + digits[i];
		}
		palindromes.push_back(num);
		return;
	}
	for (int i = 1 - !leading_digit; i < 10; ++i) {
		digits.push_back(i);
		gen_palindromes_helper(digits, depth - 1, odd);
		digits.pop_back();
	}
}

void gen_palindromes(int depth, bool odd = false) {
	deque<int> digits;
	gen_palindromes_helper(digits, depth, odd, true);
}


bool is_primenum(int num) {
	int r = sqrt(num);
	if (!(num % 2)) {
		return false;
	}
	//cout << r/2 << "\n";
	for (int i = 3; i <= r; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	//ios::sync_with_stdio(false);

	int a, b, start, end;

	fin >> a >> b;

	start = a + !(a % 2);
	end = b - !(b % 2);

	palindromes.push_back(2);

	gen_palindromes(1, true);
	int k;
	cout << "size 1 " << palindromes.size() << "\n";
	k = palindromes.size();
	gen_palindromes(1);
	cout << "size 2 " << palindromes.size() - k << "\n";
	k = palindromes.size();
	gen_palindromes(2, true);
	cout << "size 3 " << palindromes.size() - k << "\n";
	k = palindromes.size();
	gen_palindromes(2);
	cout << "size 4 " << palindromes.size() - k << "\n";
	k = palindromes.size();
	gen_palindromes(3, true);
	cout << "size 5 " << palindromes.size() - k << "\n";
	k = palindromes.size();
	gen_palindromes(3);
	cout << "size 6 " << palindromes.size() - k << "\n";
	k = palindromes.size();
	gen_palindromes(4, true);
	cout << "size 7 " << palindromes.size() - k << "\n";
	k = palindromes.size();
	gen_palindromes(4);
	cout << "size 8 " << palindromes.size() - k << "\n";

	cout << "overall size " << palindromes.size() << "\n";

	for (auto elem: palindromes) {
		if (elem >= start && elem <= end && is_primenum(elem)) {
			fout << elem << "\n";
		}
	}
	return 0;
}