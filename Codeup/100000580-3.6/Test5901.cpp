#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        int n = str.length() / 2;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (str[i] != str[str.length() - 1 - i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}