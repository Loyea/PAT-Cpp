#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str, str1, str2;
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        getline(cin, str);
        int len = str.length();
        int index = str.find(" ");
        int len1 = index;
        int len2 = len - index - 1;
        str1 = str.substr(0, index);
        str2 = str.substr(index + 1, len);

        if (len1 > len2) {
            printf("%s is longer than %s\n", str1.c_str(), str2.c_str());
        } else if (len1 == len2) {
            printf("%s is equal long to %s\n", str1.c_str(), str2.c_str());
        } else {
            printf("%s is shorter than %s\n", str1.c_str(), str2.c_str());
        }
    }

    return 0;
}