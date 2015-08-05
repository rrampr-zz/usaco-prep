/*
ID: rohitbo1
LANG: C++11
TASK: palsquare
*/
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertDecToBase(int num, int base) {
	string ans = "";
	while (num != 0) {
		char digit;
		if (num % base < 10) {
			digit = '0' + num % base;
		} else {
			digit = 'A' + num % base - 10;
		}
		ans.push_back(digit);
		num = num/base;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool isPalindrome(string& word) {
	for (int i = 0, j = word.size() - 1; i < word.size() && j >= 0; i++, j--) {
		if (word[i] != word[j]) {
			return false;
		}
	}
	return true;
}


int main() {
	ifstream f("palsquare.in");
	ofstream out("palsquare.out");
	int base;
	f >> base;
	for (int i = 1; i <= 300; ++i) {
		string new_i =  convertDecToBase(i * i, base);
		if (isPalindrome(new_i)) {
			string num  = convertDecToBase(i, base);
			out << num << " " << new_i << "\n";
		}
	}
	return 0;
}