#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


bool cmp(string a, string b) {
    return a + b < b + a;
}

int to_int(string s) {
    int i;
    sscanf(s.c_str(), "%d", &i);
    return i;
}

int main() {
    int n;
    string str[10010];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    sort(str, str + n, cmp);

    bool valid = false;
    for (int i = 0; i < n; i++) {
        int x = to_int(str[i]);
        if (valid) {
            printf("%s", str[i].c_str());
        } else {
            if (x) {
                valid = true;
                printf("%d", x);
            }
        }
    }

    if (!valid) {
        printf("0");
    }


    return 0;
}