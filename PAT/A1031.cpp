#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string input;

    cin >> input;

    int len = input.length();
    int n1, n2;

    for (int i = 3; i < len; i++) {
        n2 = i;
        if ((len - n2) % 2 != 0) {
            continue;
        }
        n1 = (len - n2) / 2 + 1;
        if (n1 <= n2) {
            break;
        }
    }

    int blank_size = n2 - 2;
    int vertical_line = n1 - 1;
    for (int i = 0; i < vertical_line; i++) {
        printf("%c", input[i]);
        for (int j = 0; j < blank_size; j++) {
            printf(" ");
        }
        printf("%c\n", input[len - 1 - i]);
    }
    for (int i = 0; i < n2; i++) {
        printf("%c", input[n1 - 1 + i]);
    }

    return 0;
}