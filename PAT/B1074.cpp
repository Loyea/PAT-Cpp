#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    int len_n = n.length();
    for (int i = 0; i < a.length() - len_n; i++) {
        a = "0" + a;
    }
    for (int i = 0; i < b.length() - len_n; i++) {
        b = "0" + b;
    }

    string result = "";

    int remain = 0;
    for (int i = len_n - 1; i >= 0; i--) {
        int p = n[i] - '0';
        if (p == 0) {
            p = 10;
        }
        int x = a[i] - '0';
        int y = b[i] - '0';
        int res = (x + y + remain) % p;
        remain = (x + y + remain) / p;
        result = to_string(res) + result;
    }

    result = to_string(remain) + result;

    bool is_zero = true;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] != '0') {
            is_zero = false;
        }
        if (!is_zero) {
            printf("%c", result[i]);
        }
    }
    if (is_zero) {
        printf("0");
    }

    return 0;
}