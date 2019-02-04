#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

char mars_low[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char mars_high[13][5] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

map<string, int> mp_low;
map<string, int> mp_high;

void to_mars(int a) {
    int q = a / 13;
    int r = a % 13;
    //这题的坑点在这，大于13的火星数字如果刚好能被13整除的话，第二位是空的
    if (q > 0) {
        printf("%s", mars_high[q]);
        if (r != 0) {
            printf(" %s", mars_low[r]);
        }
    } else {
        printf("%s", mars_low[r]);
    }
    printf("\n");
}

void to_decimal(string a[], int len) {
    if (len == 1) {
        if (mp_high.find(a[0]) != mp_high.end()) {
            printf("%d\n", mp_high[a[0]] * 13);
        } else {
            printf("%d\n", mp_low[a[0]]);
        }
    } else {
        int temp = 0;
        temp = mp_high[a[0]] * 13 + mp_low[a[1]];
        printf("%d\n", temp);
    }
}

void init() {
    for (int i = 0; i <= 13; i++) {
        string temp = mars_low[i];
        mp_low[temp] = i;
    }

    for (int i = 0; i <= 13; i++) {
        string temp = mars_high[i];
        mp_high[temp] = i;
    }
}

int main() {
    init();

    int n;
    scanf("%d", &n);
    getchar();

    string input;

    for (int i = 0; i < n; i++) {
        getline(cin, input);

        if (input[0] >= '0' && input[0] <= '9') { //decimal
            int temp = 0;
            int len = input.length();
            for (int j = 0; j < len; j++) {
                temp *= 10;
                temp += input[j] - '0';
            }
            to_mars(temp);
        } else {    //mars
            string space = " ";
            string a[2];
            if (input.find(space) != string::npos) {
                int index = input.find(space);
                a[0] = input.substr(0, index);
                a[1] = input.substr(index + 1, input.length() - 1);
                to_decimal(a, 2);
            } else {
                a[0] = input;
                to_decimal(a, 1);
            }
        }

    }


    return 0;
}