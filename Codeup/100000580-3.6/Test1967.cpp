#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {

    string str;
    while (getline(cin, str)) {
        int len = str.length();
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", str[i]);
            if (i == 0) {
                printf("\n");
            }
        }
    }


    return 0;
}