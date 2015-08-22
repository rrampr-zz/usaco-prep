/*
ID: rohitbo1
PROG: sort3
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

//Holds the numbers
int A[1001];
//Holds the count of 1,2,3 in indices 1,2,3 respectively
int ct[4];
int exchanges = 0;


void swap2(int start_index1, int start_index2, int num_elements1, int num_elements2, int target1, int target2) {
	for (int i = start_index1, j = start_index2; i < start_index1 + num_elements1 && j < start_index2 + num_elements2;) {
		if (A[i] != target2) {
			i++;
			continue;
		}
		if (A[j] != target1) {
			j++;
			continue;
		}
		exchanges++;
		swap(A[i], A[j]);
	}
}

void swap3(int i1, int i2, int i3, int n1, int n2, int n3, int t1, int t2, int t3) {
	for (int i = i1, j = i2, k = i3; 
		 i <  i1 + n1 && j < i2 + n2 && k < i3 +  n3;) {
		if (A[i] == t3 && A[j] == t1 && A[k] == t2) {
			exchanges += 2;
			swap(A[i], A[j]);
			swap(A[j], A[k]);
			continue;
		}
		if (A[i] == t2 && A[j] == t3 && A[k] == t1) {
			exchanges += 2;
			swap(A[i], A[k]);
			swap(A[k], A[j]);
			continue;
		}
		if (A[i] == t1) {
			i++;
		}
		if (A[j] == t2) {
			j++;
		}
		if (A[k] == t3) {
			k++;
		}
	}
}

int main() {
	int n;
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	fin >> n;
	for (int i = 0; i < 1000; i++) {
		fin >> A[i];
		//increment count
		++ct[A[i]];
	}

	swap2(0, ct[1], ct[1], ct[2], 1, 2);
	swap2(ct[1], ct[1] + ct[2], ct[2], ct[3], 2, 3);
	swap2(0, ct[1] + ct[2], ct[1], ct[3], 1, 3);

	swap3(0, ct[1], ct[1] + ct[2], ct[1], ct[2], ct[3], 1, 2, 3);

	fout << exchanges << "\n";
	cout << exchanges << "\n";

	return 0;
}