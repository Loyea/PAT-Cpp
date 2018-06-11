#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string n_str;
    int n;

    scanf("%d", &n);
    n_str = to_string(n);

    int len = n_str.length();

    int result = 0, product = 1;

    for (int i = len - 1; i >= 0; i--) {
        int now = n_str[i] - '0';
        int left = n / (product * 10); //当前位左侧数字
        int right = n % product;
        if (now == 0) {
            result += left * product;
        } else if (now == 1) {
            result += left * product + right + 1;
        } else {
            result += (left + 1) * product;
        }
        product *= 10;
    }

    printf("%d", result);

    return 0;
}