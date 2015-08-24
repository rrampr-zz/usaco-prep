/* 
ID: rohitbo1
LANG: C++11
PROG: friday
*/

#include <iostream>
#include <fstream>
#include <string>

#define start 1900
#define Answer_offset 2

using namespace std;

int main() {
    int thirteenInNormalYear[12] = {13, 44, 72, 103, 133, 164, 194, 225, 256, 286, 317, 347};
    int thirteenInLeapYear[12] = {13, 44, 73, 104, 134, 165, 195, 226, 257, 287, 318, 348};
    int frequency[7]= {0, 0, 0, 0, 0, 0, 0};

    ifstream fin("friday.in");
    ofstream fout("friday.out");

    bool leapYear = false;
    int number_of_years,daycounter = 0, n = 0;
    fin >> number_of_years;

    while (n < number_of_years) {
        if ((start + n) % 100 == 0 && (start + n) % 400 == 0)
            leapYear = true;
        else if ((start + n) % 100 != 0 && (start + n) % 4 == 0)
            leapYear = true;
        else
            leapYear = false;

        if (!leapYear) {
            for (int i = 0; i < 12; i++) {
                frequency[(thirteenInNormalYear[i] - 1 + daycounter + Answer_offset) % 7]++;
            }
            daycounter++;
        } else {
            for (int i = 0 ; i < 12 ; i++) {
                frequency[(thirteenInLeapYear[i] - 1 + daycounter + Answer_offset) % 7]++;
            }
            daycounter += 2;
        }

        daycounter %= 7;
        n++;
    }

    for (int i = 0; i < 7; i++) {
        fout << frequency[i];
        if (i != 6) {
            fout << " ";
        }
    }

    fout << "\n";

    return 0;
}