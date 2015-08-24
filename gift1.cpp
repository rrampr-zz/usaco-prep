/*
ID: rohitbo1
LANG: C++11
TASK: gift1
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Acct {
    int deposit;

    Acct(int cur) : deposit(cur) {}

    Acct() : deposit(0) {}
};

vector<string> names;
unordered_map<string, Acct> accounts;


int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int np;
    fin >> np;

    for (int i = 0; i < np; ++i) {
        string name;
        fin >> name;
        names.push_back(name);
    }

    for (int i = 0; i < np; ++i) {
        string name;
        fin >> name;
        int initial, num_people;
        fin >> initial >> num_people;
        if (num_people == 0) {
            continue;
        }
        accounts[name].deposit += (-1 * (initial/num_people) * num_people);
        for (int j = 0; j < num_people; ++j) {
            string receiver;
            fin >> receiver;
            accounts[receiver].deposit += initial/num_people;
        }
    }

    for (auto name : names) {
        fout << name << " " << accounts[name].deposit << "\n";
    }
    return 0;
}