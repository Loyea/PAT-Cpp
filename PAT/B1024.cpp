#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {

    string str;
    cin >> str;

    char mark = str[0];

    int e_index = str.find("E");

    string number = str.substr(1, e_index - 1);

    char mark2 = str[e_index + 1];

    string zhishu = str.substr(e_index + 2, str.length());
    int zs;
    sscanf(zhishu.c_str(), "%d", &zs);

    string num_with_dot = number;
    number.erase(1, 1);

    if (mark == '-') {
        printf("-");
    }

    int len = number.length() - 1;
    //indicates how many digits after first digit.
    if (mark2 == '+') {
        int n = zs - len;
        if (n >= 0) {
            printf("%s", number.c_str());
            for (int i = 0; i < n; i++) {
                printf("0");
            }
        } else {
            for (int i = 0; i < number.length(); i++) {
                printf("%c", number[i]);
                if (i == zs) {
                    printf(".");
                }
            }
        }
    } else {
        if (zs == 0) {
            printf("%s", num_with_dot.c_str());
        } else {
            printf("0.");
            int n = zs - 1;
            while (n--) {
                printf("0");
            }
            printf("%s", number.c_str());
        }
    }

    return 0;
}