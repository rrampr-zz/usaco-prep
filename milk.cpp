/*
ID: rohitbo1
LANG: C++11
TASK: milk
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Farmer {
	int id;
	int price;
	int milk;
};

int main() {
	int n, m;
	ifstream f_input("milk.in");
	ofstream f_output("milk.out");
	f_input >> n >> m;
	vector<Farmer> supplies(m);
	for (int i = 0; i < m; ++i) {
		supplies[i].id = i;
		f_input >> supplies[i].price;
		f_input >> supplies[i].milk;
	}
	sort(supplies.begin(),
		 supplies.end(),
		 [](const Farmer& a, const Farmer& b) {
		 	return a.price < b.price;
		 });
	long long cost = 0, milk_required = 0;
	int it = 0;
	while (milk_required != n) {
		if (supplies[it].milk + milk_required <= n) {
			milk_required += supplies[it].milk;
			cost += supplies[it].milk * supplies[it].price;
		} else {
			long long temp = n - milk_required;
			milk_required += temp;
			cost += temp * supplies[it].price;
		}
		it++;
	}
	f_output << cost << "\n";
	return 0;
}