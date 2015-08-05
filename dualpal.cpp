/*
ID: rohitbo1
LANG: C++11
TASK: dualpal
*/
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertDecToBase(int num, int base) {
	string ans = "";
	while (num != 0) {
		ans.push_back((num % base) + '0');
		num /= base;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool isPalindrome(const string& word) {
	for (int i = 0, j = word.size() - 1; i < word.size(); ++i, --j) {
		if (word[i] != word[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, s, num;
	ifstream f_in("dualpal.in");
	ofstream f_out("dualpal.out");
	f_in >> n >> s;
	s = s + 1;
	while (n != 0) {
		int num_palindromes = 0;
		for (int base = 2; base <= 10; base++) {
			if (isPalindrome(convertDecToBase(s, base))) {
				num_palindromes++;
			}
			if (num_palindromes == 2) {
				break;
			}
		}
		if (num_palindromes == 2) {
			f_out << s << "\n";
			--n;
		}
		++s;
	}
	return 0;
}