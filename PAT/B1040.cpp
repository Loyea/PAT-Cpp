#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int len = str.length();

    long p = 0, t = 0;

    long result = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'P') {
            p++;
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == 'P') {
            p--;
        } else if (str[i] == 'T') {
            t++;
        } else {
            result = (result + p * t) % 1000000007;
        }
    }

    printf("%lld", result);

    return 0;
}