#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char cn[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

char unit[10][10] = {"", "Shi", "Bai", "Qian"}; //single digit have no unit name.

int main() {

    int i, absi;
    scanf("%d", &i);
    absi = abs(i);

    string result = "";

    if (i == 0) {
        printf("ling");
        return 0;
    }

    if (i < 0) {
        result = result + "Fu ";
    }

//    bool is_zero = false;//indicates current last word of result is 'ling' or not.

    bool is_zero = false; //indicates 'zero' found.

    int a = absi / 100000000;
    if (a > 0) {
        result = result + cn[a] + " Yi ";
    }

    absi = absi % 100000000;

    int b = absi / 10000;


    int p = 1000;
    int p_count = 3;
    for (int i = 0; i < 4; i++) {
        int temp = b / p % 10;
        if (temp != 0) {
            if (is_zero) {
                result = result + "ling ";
                is_zero = false;
            }
            result = result + cn[temp] + " ";
            if (p != 1) {
                result = result + unit[p_count] + " ";
            }
        } else {
            //temp == 0
            if (p != 1 && result.length() != 0 && result != "Fu ") {
                is_zero = true;
            }
        }


        p = p / 10;
        p_count--;
    }

    if (b > 0) {
        result = result + "Wan ";
    }

    int c = absi % 10000;
    int p2 = 1000;
    int p2_count = 3;
    for (int i = 0; i < 4; i++) {
        int temp = c / p2 % 10;
        if (temp != 0) {
            if (is_zero) {
                result = result + "ling ";
                is_zero = false;
            }
            result = result + cn[temp];
            if (p2 != 1) {
                result = result + " ";
                result = result + unit[p2_count] + " ";
            }
        } else {
            if (p2 != 1 && result.length() != 0 && result != "Fu ") {
                is_zero = true;
            }
        }

        p2 = p2 / 10;
        p2_count--;
    }

    if (result[result.length() - 1] == ' ') {
        result = result.substr(0, result.length() - 1);
    }

    printf("%s", result.c_str());

    return 0;
}