/*
ID: rohitbo1
LANG: C++11
PROG: ride
*/

#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int encrypt(std::string &, int mod = 47);

int main() {
    string name,name1;
    fstream input("ride.in", std::fstream::in), output("ride.out", std::fstream::out);

    input >> name >> name1;

    if(encrypt(name) == encrypt(name1))
        output << "GO\n";
    else
        output << "STAY\n";

    return 0;
}

int encrypt(std::string &name, int mod) {
    int a = 1;
    for(auto it:name) {
        a *= (it - 'A' + 1);
        a %= mod;
    }
    return a;
}