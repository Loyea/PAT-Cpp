#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {

    string str[110];
    int count = 0;

    int m;
    scanf("%d", &m);
    getchar();
    while (m--) {
        getline(cin, str[count++]);
        int j = 1;
        for (int i = count - 1; i >= 0 && j <= 4; i--, j++) {
            printf("%d=%s", j, str[i].c_str());
            if (i != 0 && j != 4) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }

    return 0;
}