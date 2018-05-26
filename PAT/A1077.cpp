#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str[110];
    int n;
    scanf("%d", &n);
    getchar();
    int shortest_len;
    for (int i = 0; i < n; i++) {
        getline(cin, str[i]);
        reverse(str[i].begin(), str[i].end());
        if (i == 0) {
            shortest_len = str[i].length();
        }
        if (str[i].length() < shortest_len) {
            shortest_len = str[i].length();
        }
    }

    string result = "";
    char temp;
    for (int i = 0; i < shortest_len; i++) {
        temp = str[0][i];
        bool same = true;
        for (int j = 0; j < n; j++) {
            if (temp != str[j][i]) {
                same = false;
                break;
            }
        }
        if (same) {
            result = result + temp;
        } else {
            break;
        }
    }

    if (result.length() > 0) {
        reverse(result.begin(), result.end());
        printf("%s", result.c_str());
    } else {
        printf("nai");
    }

    return 0;
}